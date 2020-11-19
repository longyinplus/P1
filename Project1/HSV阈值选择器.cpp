#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int flag;

void minH_cb(int a, void* data)
{
	flag = 1;
}
void maxH_cb(int a, void* data)
{
	flag = 1;
}
void minS_cb(int a, void* data)
{
	flag = 1;
}
void maxS_cb(int a, void* data)
{
	flag = 1;
}
void minV_cb(int a, void* data)
{
	flag = 1;
}
void maxV_cb(int a, void* data)
{
	flag = 1;
}

int main()
{
	Mat src_Img, HSV_Img, result;
	int i_minH = 0;
	int i_maxH = 255;
	int i_minS = 0;
	int i_maxS = 255;
	int i_minV = 0;
	int i_maxV = 255;
	char key;
	namedWindow("TOOLS");
	createTrackbar("minH", "TOOLS", &i_minH, 255, minH_cb);
	createTrackbar("maxH", "TOOLS", &i_maxH, 255, maxH_cb);
	createTrackbar("minS", "TOOLS", &i_minS, 255, minS_cb);
	createTrackbar("maxS", "TOOLS", &i_maxS, 255, maxS_cb);
	createTrackbar("minV", "TOOLS", &i_minV, 255, minV_cb);
	createTrackbar("maxV", "TOOLS", &i_maxV, 255, maxV_cb);
	src_Img = imread("E:\\opencv\\pictures\\apple.jpg");
	namedWindow("SHOW", CV_WINDOW_NORMAL);
	namedWindow("SRC", CV_WINDOW_NORMAL);
	waitKey(1);
	flag = 0;
	while (1) {
		if (flag) {
			inRange(src_Img, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), HSV_Img);
			imshow("SHOW", HSV_Img);
			imshow("SRC", src_Img);
		}
		key = waitKey(1);
		if (key = ' ') break;
	}

}