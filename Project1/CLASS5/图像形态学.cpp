#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src_Img, IO_Img, kernel, Erode_Img, Dilate_Img, Open_Img, Close_Img;
	Size size;
	size.height = 3;
	size.width = 3;
	src_Img = imread("E:\\opencv\\pictures\\coins.png", 0);
	threshold(src_Img, IO_Img, 100, 255, THRESH_BINARY);
	imshow("abab", IO_Img);
	kernel = getStructuringElement(MORPH_RECT, size);
	morphologyEx(IO_Img, Erode_Img, MORPH_ERODE, kernel);
	morphologyEx(IO_Img, Dilate_Img, MORPH_DILATE, kernel);
	morphologyEx(IO_Img, Open_Img, MORPH_OPEN, kernel);
	morphologyEx(IO_Img, Close_Img, MORPH_CLOSE, kernel);
	imshow("∏Ø ¥", Erode_Img);
	imshow("≈Ú’Õ", Dilate_Img);
	imshow("ø™‘ÀÀ„", Open_Img);
	imshow("±’‘ÀÀ„", Close_Img);
	waitKey(0);
}