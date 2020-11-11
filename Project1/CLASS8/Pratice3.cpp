#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int Flag = 1; //��ǻ������Ƿ��ж���
void Thre_Track(int a, void* data)
{
	Flag = 1;
}

void minLineLength_Track(int a, void* data)
{
	Flag = 1;
}

void maxLineGap_Track(int a, void* data)
{
	Flag = 1;
}

int main()
{
	Mat src_Img, Binary_Img;
	vector<Vec4i> lines;
	char key;
	double step = 1, step_theta = CV_PI / 180;
	Point2f pt1, pt2;
	int Threshold = 39, minLineLength = 52, maxLineGap = 12;
	namedWindow("Tools");
	createTrackbar("ͶƱ�����ֵ", "Tools", &Threshold, 200, Thre_Track);
	createTrackbar("��С�߳�", "Tools", &minLineLength, 200, minLineLength_Track);
	createTrackbar("�����", "Tools", &maxLineGap, 200, maxLineGap_Track);
	src_Img = imread("E:\\opencv\\pictures\\Part.jpg", 0);
	int width = src_Img.cols, height = src_Img.rows;
	cv::threshold(src_Img, Binary_Img, 100, 255, 0);
	Canny(Binary_Img, Binary_Img, 100, 200);
	imshow("��ֵ��", Binary_Img);
	while (1) {
		if (Flag) {
			Flag = 0;
			Mat Show_Img;
			src_Img.copyTo(Show_Img);
			HoughLinesP(Binary_Img, lines, step, step_theta, Threshold, minLineLength, maxLineGap);
			if (lines.size())
				cout << "Find lines" << endl;
			for (int j = 0; j < lines.size(); j++) {
				Vec4i P = lines[j];
				pt1.x = P[0];
				pt1.y = P[1];
				pt2.x = P[2];
				pt2.y = P[3];
				cout << pt1 << pt2 << endl;
				line(Show_Img, pt1, pt2, Scalar(255, 255, 255), 2, CV_AA);
			}
			imshow("����", Show_Img);
		}
		key = waitKey(1);
		if (key == ' ')
			break;
	}

}