#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap;
	Mat frame, Blur;
	Size size;
	char key;
	bool ret;
	cap.open(0);
	if (!cap.open(0)) {
		cout << "�޷�������ͷ" << endl;
		return 0;
	}
	size.width = 5;
	size.height = 5;
	while (1) {
		ret = cap.read(frame);
		if (ret) {
			blur(frame, Blur, size);
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