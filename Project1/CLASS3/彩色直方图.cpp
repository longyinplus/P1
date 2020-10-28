#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

#define Red		1
#define Green   2
#define Blue	3
void Draw(int color, Mat Img)
{
	float histgram[256] = { 0 };
	Point start, end;
	int width, heigth, x, y, Sum;
	width = Img.cols;
	heigth = Img.rows;
	for (y = 0; y < heigth; y++) {
		uchar* data = Img.ptr<uchar>(y);
		for (x = 0; x < width; x++) {
			histgram[data[x]]++;
		}
	}
	Mat Show(500, 255, CV_8UC3, Scalar(255, 255, 255));
	Sum = width * heigth;
	for (x = 0; x < 256; x++) {
		histgram[x] = histgram[x] / Sum;
	}
	for (x = 0; x < 255; x++) {
		start.x = x;
		start.y = 500;
		end.x = x;
		end.y = 500 - (int)(histgram[x] * 8000);
		switch (color) {
		case Red:
			line(Show, start, end, CV_RGB(255, 0, 0), 1, 8, 0);
			break;
		case Green:
			line(Show, start, end, CV_RGB(0, 255, 0), 1, 8, 0);
			break;
		case Blue:
			line(Show, start, end, CV_RGB(0, 0, 255), 1, 8, 0);
			break;
		}
	}
	switch (color) {
	case Red:
		imshow("Red", Show); break;
	case Green:
		imshow("Green", Show); break;
	case Blue:
		imshow("Blue", Show); break;
	}
}

int main()
{
	Mat src_Img, B, G, R;
	Point start, end;
	std::vector<Mat> channels;
	float histgram_b[256] = { 0 }, histgram_g = { 0 }, histgram_r = { 0 };
	src_Img = imread("E:\\opencv\\pictures\\rainbow.png");
	split(src_Img, channels);
	B = channels.at(0);
	G = channels.at(1);
	R = channels.at(2);
	imshow("src", src_Img);
	Draw(Blue, B);
	Draw(Green, G);
	Draw(Red, R);
	waitKey(0);
	return 0;
}