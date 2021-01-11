#include<iostream>
#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	cap.open("C:\\Users\\97008\\Desktop\\����ҵ\\��ͼ\\����ҵ\\����3.mp4");
	if (!cap.isOpened()) {
		cout << "��ʧ��" << endl;
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