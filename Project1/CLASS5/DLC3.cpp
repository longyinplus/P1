#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src_Img, Gray_Img, IO_Img, kernel, OK_Img, Labels, Stats, Centroids;
	Size size;
	Point Start, End;
	int  Count = 0;
	src_Img = imread("E:\\opencv\\pictures\\CLASS5-3.png");
	cvtColor(src_Img, Gray_Img, CV_RGB2GRAY);
	threshold(Gray_Img, IO_Img, 100, 255, THRESH_BINARY_INV);
	imshow("二值化结果", IO_Img);
	size.height = 21;
	size.width = 21;
	kernel = getStructuringElement(MORPH_RECT, size);
	morphologyEx(IO_Img, OK_Img, MORPH_OPEN, kernel);
	imshow("预处理结果", OK_Img);	//开运算去除线

	connectedComponentsWithStats(OK_Img, Labels, Stats, Centroids, 8, CV_32S);
	for (int a = 0; a < Stats.rows; a++) {
		long* data = Stats.ptr<long>(a);
		if (data[4] < 10000) {		//太大的连通域肯定是背景
			Count++;
			Start.x = data[0];
			Start.y = data[1];
			End.x = Start.x + data[2];
			End.y = Start.y + data[3];
			rectangle(src_Img, Start, End, CV_RGB(72, 142, 62), 3);
		}
	}
	imshow("标记结果", src_Img);
	cout << "计数结果为:" << Count << endl;
	waitKey(0);

	return 0;
}