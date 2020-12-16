#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

#define Step	0.1

int Select_x = 0;
int Select_y = 0;
int CallBack_Flag = 1;

void onMouse(int Event, int x, int y, int flags, void* userdata)
{
	if (flags == EVENT_LBUTTONDOWN && CallBack_Flag) { //如果左键双击
		Select_x = x;
		Select_y = y;
		CallBack_Flag = 0;								 //选定了就不再改了
	}
}

int main()
{
	VideoCapture cap;
	Mat frame;
	Mat Show(240, 512, CV_8UC3, Scalar(255, 255, 255));
	float Table[512] = { 0 };
	cap.open(0);
	namedWindow("Video", WINDOW_NORMAL);
	namedWindow("show", WINDOW_AUTOSIZE);
	setMouseCallback("Video", onMouse);
	imshow("show", Show);
	while (cap.isOpened()) {
		bool ret = cap.read(frame);
		if (ret) {
			if (CallBack_Flag == 0) {						//如果已经选好点了
				Mat gray;
				cvtColor(frame, gray, COLOR_BGR2GRAY);
				uchar* data = frame.ptr<uchar>(Select_y);
				Table[data[Select_x]] += Step;
				for (int n = 0; n < 256; n++) {
					Point Start, End;
					Start.x = n * 2;
					End.x = n * 2;
					Start.y = 240-1;
					End.y = 2 * (120 - floor(Table[n])) - 1;
					if (End.y <= 0)
						End.y = 0;
					line(Show, Start, End, Scalar(86, 156, 214), 2);
				}
				circle(frame, Point(Select_x, Select_y), 5, Scalar(214, 157, 133), -1);
				imshow("show", Show);
			}
			imshow("Video", frame);
			char key = waitKey(1);
			if (key == ' ') break;
		}
	}
	destroyAllWindows();
}