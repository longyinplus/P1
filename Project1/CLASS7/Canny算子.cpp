#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat result, gray;
	Mat src_Img = imread("E:\\opencv\\pictures\\Jotara.png");
	cvtColor(src_Img, gray, CV_BGR2GRAY);
	Canny(gray, result, 150, 100);
	imshow("�޵��޵��޵�", src_Img);
	imshow("զ��³��", result);
	waitKey(0);
	return 0;
}