#include<iostream>
#include<opencv2/opencv.hpp>
#include<stdlib.h>
#define CellSize	20

using namespace cv;
using namespace std;

int Simple_Hog(Mat src_Img, float* List, int nAngle, int Size)
{
	Mat Img_x, Img_y;
	Mat mag, angle;
	int ny = src_Img.rows / CellSize;
	int nx = src_Img.cols / CellSize;
	int x, y;
	Sobel(src_Img, Img_x, CV_32F, 1, 0, 1);
	Sobel(src_Img, Img_y, CV_32F, 0, 1, 1);

	cartToPolar(Img_x, Img_y, mag, angle, true);	//得到这张图中每个像素点的方向和幅值

	for (y = 0; y < ny; y++) {
		for (x = 0; x < nx; x++) {
			Mat roiImg, roiMag, roiAngle;
			Rect roi = Rect(x * CellSize, y * CellSize, CellSize, CellSize);
			roiImg = src_Img(roi);
			roiMag = mag(roi);
			roiAngle = angle(roi);
			int Start = (y * nx + x) * nAngle;
			float step = 360 / nAngle;	//角度区域的大小
			//float step = 2.0 / (float)nAngle;
			for (int n = 0; n < roiImg.rows; n++) {
				float* Data_angle = roiAngle.ptr<float>(n);
				float* Data_mag = roiMag.ptr<float>(n);
				for (int m = 0; m < roiImg.cols; m++) {
					int Num = floor(roiAngle.at<float>(n, m) / step);	//算出这一点像素角度在第几个分区
					List[Start + Num] += roiMag.at<float>(n, m);
				}
			}
		}
	}
	return 0;
}

float Hist_Distance(float* Hist1, float* Hist2, int Num)
{
	int sum = 0;
	float result;
	for (int n = 0; n < Num; n++) {
		sum += (Hist1[n] - Hist2[n]) * (Hist1[n] - Hist2[n]);
	}
	result = sqrt(sum);
	return result;
}

float My_HOG(Mat Input, Mat Temp_Img)
{
	int nAngle = 8;
	int ny = Temp_Img.rows / CellSize;
	int nx = Temp_Img.cols / CellSize;
	int bin = ny * nx * nAngle;
	float* ref_Hist = new float[bin];
	memset(ref_Hist, 0, sizeof(float) * bin);
	float* r_Hist = new float[bin];
	memset(r_Hist, 0, sizeof(float) * bin);
	int reCode = 0;
	reCode = Simple_Hog(Temp_Img, ref_Hist, nAngle, CellSize);
	reCode = Simple_Hog(Input, r_Hist, nAngle, CellSize);
	float Dis1 = Hist_Distance(ref_Hist, r_Hist, bin);
	delete[] ref_Hist;
	delete[] r_Hist;
	return Dis1;
}

void Progress_Bar(int t, int max, Mat* img)		//加载进度条, 等待不无聊(双押)
{
	Point Text_start, Text_end, Line_start, Line_end;
	Text_start.x = img->cols / 2 - 50;
	Text_start.y = 10;
	Text_end.x = img->cols / 2 + 55;
	Text_end.y = 10;
	Line_start.x = Text_start.x + 5;
	Line_start.y = 8;
	Line_end.y = 8;
	putText(*img, "<", Text_start, FONT_HERSHEY_SIMPLEX, 0.3, Scalar(255, 0, 255), 2);
	Line_end.x = Line_start.x + t * 100 / max;
	line(*img, Line_start, Line_end, Scalar(255, 255, 50), 2);
	putText(*img, ">", Text_end, FONT_HERSHEY_SIMPLEX, 0.3, Scalar(255, 0, 255), 2);
}

int main()
{
	Mat Temp_Img, Test_Right, Test_Wrong, Choose_Img;
	Mat Bar(30, 200, CV_8UC3, Scalar(255, 255, 255));
	Rect Choose_rect;
	Point result_Point;
	int nAngle = 8;
	float now, Max = 0;
	int height, weight;

	Temp_Img = imread("E:\\opencv\\pictures\\Class14_Temp.png", 0);
	Test_Right = imread("E:\\opencv\\pictures\\Class14.png", 0);

	height = Test_Right.rows - Temp_Img.rows + 1;
	weight = Test_Right.cols - Temp_Img.cols + 1;
	Choose_rect.width = Temp_Img.cols;
	Choose_rect.height = Temp_Img.rows;
	for (int y = 0; y < height; y+=5) {
		for (int x = 0; x < weight; x+=5) {
			Choose_rect.y = y;
			Choose_rect.x = x;
			Test_Right(Choose_rect).copyTo(Choose_Img);	//把被窗户框中的部分截下来
			Progress_Bar((y + 1) * weight + x + 1, height * weight, &Bar);
			now = My_HOG(Choose_Img, Temp_Img);
			if (now > Max) {
				Max = now;
				result_Point.x = x;
				result_Point.y = y;
			}
			waitKey(1);
			imshow("windows", Bar);
		}
	}

	Rect Match_rect;
	Match_rect.x = result_Point.x;
	Match_rect.y = result_Point.y;
	Match_rect.width = Temp_Img.cols;
	Match_rect.height = Temp_Img.rows;
	rectangle(Test_Right, Match_rect, Scalar(82, 144, 67), 3);
	imshow("result", Test_Right);
	waitKey(0);
	return 0;
}