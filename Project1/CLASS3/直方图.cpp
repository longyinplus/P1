#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat src_Img;
	Point start, end;
	int width, heigth, x, y;
	float histgram[256] = { 0 };
	src_Img = imread("E:\\opencv\\pictures\\cat.jpg", 0);
	width = src_Img.cols;
	heigth = src_Img.rows;
	for (y = 0; y < heigth; y++) {
		uchar* data = src_Img.ptr<uchar>(y);
		for (x = 0; x < width; x++) {
			histgram[data[x]]++;
		}
	}
	int Sum = width * heigth;
	for (x = 0; x < 256; x++) {
		histgram[x] /= Sum;
		std::cout << x << ":" << histgram[x] << std::endl;
	}
	Mat Show(700, 255, CV_8UC3, Scalar(255, 0, 0));
	for (x = 0; x < 255; x++) {
		start.x = x;
		start.y = 700;
		end.x = x;
		end.y = 700 - int(histgram[x] * 1000);
		line(Show, start, end, CV_RGB(255, 0, 0), 1, 8, 0);
	}
	imshow("result", Show);
	imshow("src", src_Img);
	waitKey(0);
	return 0;
}