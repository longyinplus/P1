#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat src_Img;
	Point a, b;
	Rect rect;
	src_Img = imread("E:\\opencv\\pictures\\work3-1.png");
	a.x = 50;
	a.y = 50;
	circle(src_Img, a, 50, CV_RGB(255, 0, 0), 5, 8, 0);
	imshow("SHOW", src_Img);
	waitKey(0);
	a.x = 100;
	a.y = 100;
	b.x = 200;
	b.y = 100;
	line(src_Img, a, b, CV_RGB(0, 255, 0), 5, 8, 0);
	imshow("SHOW", src_Img);
	waitKey(0);
	rect.x = 100;
	rect.y = 300;
	rect.width = 100;
	rect.height = 100;
	rectangle(src_Img, rect, CV_RGB(0, 0, 255), 5, 8, 0);
	imshow("SHOW", src_Img);
	waitKey(0);
	return 0;
}