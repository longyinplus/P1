#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src_Img, Binary_Img, Red_Channel;
	Mat splitChannles[3];
	src_Img = imread("E:\\opencv\\pictures\\apple.jpg");
	split(src_Img, splitChannles);
	namedWindow("��ɫ", CV_WINDOW_NORMAL);
	namedWindow("��ɫ��ֵ��", CV_WINDOW_NORMAL);
	imshow("��ɫ", splitChannles[2]);
	threshold(splitChannles[2], Binary_Img, 210, 255, 0);
	imshow("��ɫ��ֵ��", Binary_Img);
	waitKey(0);
}