#include <iostream>
#include <opencv2/opencv.hpp>
#define size 3
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap;
	Mat frame, Border_x, Border_y, Border_x2;
	char key;
	bool ret;
	cap.open(0);
	if (!cap.open(0)) {
		cout << "无法打开摄像头" << endl;
		return 0;
	}
	while (1) {
		ret = cap.read(frame);
		if (ret) {
			cvtColor(frame, frame, CV_BGR2GRAY);
			Sobel(frame, Border_x, CV_16SC1, 0, 1, 1);
			Sobel(frame, Border_y, CV_16SC1, 1, 0, 1);
			convertScaleAbs(Border_x, Border_x2);
		}
		else {
			cout << "读取帧图像失败" << endl;
		}
		imshow("原图", frame);
		imshow("视频x", Border_x);
		imshow("视频x2", Border_x2);
		imshow("视频y", Border_y);
		key = waitKey(10);
		if (key == ' ') {
			destroyAllWindows();
			break;
		}
	}
	return 0;
}