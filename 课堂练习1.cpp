#include<iostream>
#include<opencv2/opencv.hpp>
#define threshold  50
using namespace cv;

int main()
{
	int height, width, x, y;
	uchar avg;
	Mat Img = imread("E:\\opencv\\pictures\\qiqiu.jpg"), Img1, Img2, Gray;
	namedWindow("原图像", CV_WINDOW_NORMAL);
	imshow("原图像", Img);
	waitKey(1);
	height = Img.rows;
	width = Img.cols;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			avg = Img.at<Vec3b>(y, x)[0] + Img.at<Vec3b>(y, x)[1] + Img.at<Vec3b>(y, x)[2];
			avg = avg / 3;
			Img.at<Vec3b>(y, x)[0] = avg;
			Img.at<Vec3b>(y, x)[1] = avg;
			Img.at<Vec3b>(y, x)[2] = avg;
		}
	}
	Img.copyTo(Img1);
	namedWindow("第一次处理", CV_WINDOW_NORMAL);
	imshow("第一次处理", Img1);
	waitKey(0);
	Gray = imread("E:\\opencv\\pictures\\Lu.png", 0);
	namedWindow("黑白图", CV_WINDOW_NORMAL);
	imshow("黑白图", Gray);
	waitKey(0);
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			if (Img.at<Vec3b>(y, x)[0] > threshold) {
				Img.at<Vec3b>(y, x)[0] = 255;
				Img.at<Vec3b>(y, x)[1] = 255;
				Img.at<Vec3b>(y, x)[2] = 255;
			}
			else {
				Img.at<Vec3b>(y, x)[0] = 0;
				Img.at<Vec3b>(y, x)[1] = 0;
				Img.at<Vec3b>(y, x)[2] = 0;
			}
		}
	}
	Img.copyTo(Img2);
	namedWindow("第二次处理", CV_WINDOW_NORMAL);
	imshow("第二次处理", Img2);
	waitKey(0);

}