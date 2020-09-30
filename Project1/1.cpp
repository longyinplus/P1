#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat src_Img, B, G, R;
	std::vector<Mat> channels;
	src_Img = imread("E:\\opencv\\pictures\\qiqiu.jpg");
	split(src_Img, channels);
	B = channels.at(0);
	G = channels.at(1);
	R = channels.at(2);
	namedWindow("red", CV_WINDOW_NORMAL);
	namedWindow("green", CV_WINDOW_NORMAL);
	namedWindow("blue", CV_WINDOW_NORMAL);
	imshow("red", R);
	imshow("green", G);
	imshow("blue", B);
	imshow("src", src_Img);
	waitKey(0);
	return 0;
}