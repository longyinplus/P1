#include <iostream>
#include <opencv2/opencv.hpp>
#define Erea_Type	THRESH_BINARY
#define All_Type	THRESH_BINARY
#define All_Method	ADAPTIVE_THRESH_GAUSSIAN_C

using namespace cv;
using namespace std;

int  Erea_blockSize = 15;
double All_Thre = 100, Erea_C = 3;
Mat All_Result, Erea_Result, srcImg;

void AThre_Track(int a, void* data) //全局二值化阈值调整
{
	threshold(srcImg, All_Result, a, 255, Erea_Type);
	return;
}

void EBlockSize_Track(int a, void* data) //局域二值化区域块大小调整
{
	if (a < 3)
		a = 3;
	if (a % 2 == 0)
		a++;
	Erea_blockSize = a;
	adaptiveThreshold(srcImg, Erea_Result, 255, All_Method, All_Type, Erea_blockSize, (double)Erea_C);
	return;
}

void EC_Track(int a, void* dat) //局域二值化偏移值大小调整
{
	Erea_C = a;
	adaptiveThreshold(srcImg, Erea_Result, 255, All_Method, All_Type, Erea_blockSize, Erea_C);
	return;
}

int main()
{
	char key;
	int a = 100, b = 15, c = 3;
	srcImg = imread("E:\\opencv\\pictures\\HunAn.png", 0);
	threshold(srcImg, All_Result, All_Thre, 255, Erea_Type);
	adaptiveThreshold(srcImg, Erea_Result, 255, All_Method, All_Type, 15, 3);
	namedWindow("Trackbars", CV_WINDOW_NORMAL);
	createTrackbar("All_Thre", "Trackbars", &a, 255, AThre_Track);
	createTrackbar("Erea_BlockSize", "Trackbars", &b, 100, EBlockSize_Track);
	createTrackbar("Erea_C", "Trackbars", &c, 30, EC_Track);
    imshow("source", srcImg);
	while (1) {
		imshow("Erea", Erea_Result);
		imshow("All", All_Result);
		key = waitKey(50);
		if (key == ' ') break;
	}
	destroyAllWindows();
}
