#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	Mat frame, Background, subMat, Binary_Img;
	bool ret = 0;
	cap.open("E:\\opencv\\movies\\killer.mp4");
	while (!ret)
		ret = cap.read(Background);		//读取第一帧图像作为背景
	cvtColor(Background, Background, COLOR_BGR2GRAY);
	namedWindow("b_subMat", WINDOW_NORMAL);
	namedWindow("subMat", WINDOW_NORMAL);
	namedWindow("source", WINDOW_NORMAL);
	while (cap.isOpened()) {
		ret = cap.read(frame);
		if (ret) {
			imshow("source", frame);
			cvtColor(frame, frame, COLOR_BGR2GRAY);
			absdiff(frame, Background, subMat);
			threshold(subMat, Binary_Img, 50, 255, CV_THRESH_BINARY);
			imshow("b_subMat", Binary_Img);
			imshow("subMat", subMat);
			char key = waitKey(30);
			if (key == ' ') break;
		}
	}
	destroyAllWindows();
}