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
		cout << "无法打开摄像头" << endl;
		return 0;
	}
	while (1) {
		ret = cap.read(frame);
		if (ret) {
			medianBlur(frame, Blur, size);
		}
		else {
			cout << "读取帧图像失败" << endl;
		}
		key = waitKey(1);
		imshow("视频", Blur);
		if (key == ' ') {
			destroyAllWindows();
			break;
		}
	}
	return 0;
}