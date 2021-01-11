#include<iostream>
#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	cap.open("C:\\Users\\97008\\Desktop\\大作业\\数图\\大作业\\附件3.mp4");
	if (!cap.isOpened()) {
		cout << "打开失败" << endl;
		return 1;
	}
	while (cap.isOpened()) {
		Mat frame;
		bool ret = cap.read(frame);
		if (ret) {
			imshow("src", frame);
			char key = waitKey(1);
			if (key == ' ')
				break;
		}
		else
		{
			waitKey(0);
			break;
		}
	}
	destroyAllWindows();
	return 0;
}