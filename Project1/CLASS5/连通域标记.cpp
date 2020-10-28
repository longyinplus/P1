#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src_Img, Gray_Img, IO_Img, kernel, Close_Img, Labels, Stats, Centroids;
	Size size;
	Point Start, End;
	int  Count = 0, n;
	size.height = 3;
	size.width = 3;
	src_Img = imread("E:\\opencv\\pictures\\coins.png");
	cvtColor(src_Img, Gray_Img, CV_RGB2GRAY);
	threshold(Gray_Img, IO_Img, 100, 255, THRESH_BINARY);
	imshow("abab", IO_Img);
	kernel = getStructuringElement(MORPH_RECT, size);
	morphologyEx(IO_Img, Close_Img, MORPH_CLOSE, kernel);
	imshow("闭运算", Close_Img);	//闭运算去除噪声

	connectedComponentsWithStats(Close_Img, Labels, Stats, Centroids, 8, CV_32S);
	for (int a = 0; a < Stats.rows; a++) {
		long* data = Stats.ptr<long>(a);
		if (data[4] < 10000) {		//太大的连通域肯定是背景
			Count++;
			Start.x = data[0];
			Start.y = data[1];
			End.x = Start.x + data[2];
			End.y = Start.y + data[3];
			rectangle(src_Img, Start, End, CV_RGB(72, 142, 62), 3);
			imshow("标记结果", src_Img);
			waitKey(1);
		}
	}
	cout << "计数结果为:" << Count << endl;
	waitKey(0);

	return 0;
}