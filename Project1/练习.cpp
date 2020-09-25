#include <iostream>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat dstM;
	int x, y;
	std::cout << "hello oO0ill1Lpencv" << std::endl;
	//cv::Mat srcImage = cv::imread("E:/opencv/pictures/cat.jpg");
	Mat srcM(2, 3 , CV_8UC3, Scalar(0, 0, 255));
	for (y = 0; y < srcM.rows; y++) {
		for (x = 0; x < srcM.cols; x++) {
			srcM.at<Vec3b>(y, x)[0] = y;
			srcM.at<Vec3b>(y, x)[1] = y + 1;
			srcM.at<Vec3b>(y, x)[2] = y + 2;
		}
	}
	std::cout << srcM << std::endl;
	system("pause");
	return 0;
}