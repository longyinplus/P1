#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src_Img, Range_Img, Binary_Img, Red_Channel;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	RotatedRect rbox;
	int n;
	int i_minH = 0;
	int i_maxH = 185;
	int i_minS = 26;
	int i_maxS = 97;
	int i_minV = 104;
	int i_maxV = 255;
	src_Img = imread("E:\\opencv\\pictures\\apple.jpg");
	inRange(src_Img, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), Range_Img);
	threshold(Range_Img, Binary_Img, 200, 255, 0);
	namedWindow("颜色过滤", CV_WINDOW_NORMAL);
	imshow("颜色过滤", Binary_Img);
	resizeWindow("颜色过滤", 320, 480);
	waitKey(1);
	findContours(Binary_Img, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	for (n = 0; n < contours.size(); n++) {
		rbox = minAreaRect(contours[n]);
		if (rbox.size.area() > 890000){
			cout << rbox.size.area() << endl;
			drawContours(src_Img, contours, n, Scalar(246, 6, 246), 5, 8);
			rectangle(src_Img, rbox.boundingRect(), Scalar(255, 100, 0), 20);
		}
	}
	namedWindow("结果", CV_WINDOW_NORMAL);
	resizeWindow("结果", 640, 480);
	imshow("结果", src_Img);
	waitKey(0);
	return 0;
}