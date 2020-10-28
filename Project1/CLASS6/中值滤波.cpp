#include <iostream>
#include <opencv2/opencv.hpp>
#define size 31
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap;
	Mat frame, Blur;
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
			medianBlur(frame, Blur, size);
		}
		else {
			cout << "��ȡ֡ͼ��ʧ��" << endl;
		}
		key = waitKey(1);
		imshow("��Ƶ", Blur);
		if (key == ' ') {
			destroyAllWindows();
			break;
		}
	}
	return 0;
}