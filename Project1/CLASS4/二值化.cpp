#include <iostream>
#include <opencv2/opencv.hpp>
#define Erea_Type	THRESH_BINARY
#define All_Type	THRESH_BINARY
#define All_Method	ADAPTIVE_THRESH_GAUSSIAN_C

using namespace cv;
using namespace std;

int main()
{
	Mat All_Result, Erea_Result;
	Mat srcImg = imread("E:\\opencv\\pictures\\HunAn.png", 0);
	threshold(srcImg, All_Result, 100, 255, Erea_Type);
	adaptiveThreshold(srcImg, Erea_Result, 255, All_Method, All_Type, 15, 3);
	imshow("Resource", srcImg);
	imshow("Erea", Erea_Result);
	imshow("All", All_Result);
	waitKey(0);
	destroyAllWindows();
}
