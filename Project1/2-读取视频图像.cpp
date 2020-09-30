#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened()) {
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (11) {
		Mat Frame;
		bool rSuccess = cap.read(Frame);
		if (!rSuccess) {
			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
			break;
		}
		else {
			imshow("Frame", Frame);
		}
		char key = waitKey(30);
		if (key == 'q') break;
	}
	return 1;
}