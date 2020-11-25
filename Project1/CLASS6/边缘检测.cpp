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
		cout << "�޷�������ͷ" << endl;
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
			cout << "��ȡ֡ͼ��ʧ��" << endl;
		}
		imshow("ԭͼ", frame);
		imshow("��Ƶx", Border_x);
		imshow("��Ƶx2", Border_x2);
		imshow("��Ƶy", Border_y);
		key = waitKey(10);
		if (key == ' ') {
			destroyAllWindows();
			break;
		}
	}
	return 0;
}