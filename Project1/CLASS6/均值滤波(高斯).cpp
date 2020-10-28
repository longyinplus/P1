#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void Track(int a, void* dat)
{
	;
}

int main()
{
	VideoCapture cap;
	Mat frame, Blur;
	Size size;
	char key;
	bool ret;
	int x = 7;
	size.width = 13;
	size.height = 13;
	namedWindow("Trackbars", CV_WINDOW_NORMAL);
	createTrackbar("sigma-x", "Trackbars", &x, 255, Track);//创建一个滑动条, 用来调高斯滤波的sigma
	cap.open(0);
	if (!cap.open(0)) {
		cout << "无法打开摄像头" << endl;
		return 0;
	}
	while (1) {
		ret = cap.read(frame);
		if (ret) {
			GaussianBlur(frame, Blur, size, x, 5);
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