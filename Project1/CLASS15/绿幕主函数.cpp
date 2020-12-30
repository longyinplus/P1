// dip-class-demos.cpp : 定义控制台应用程序的入口点。
//

#include <opencv.hpp>
#include "green_funtions.h"

using namespace cv;
using namespace std;

int main()
{
	//开始计时
	double start = static_cast<double>(cvGetTickCount());
	VideoCapture Dragon_cap;
	VideoCapture Back_cap;
	Rect Cut;		//用来把烦人的抖音logo去掉
	Cut.x = 0;
	Cut.y = 0;
	Cut.height = 400;
	Cut.width = 320;
	Dragon_cap.open("C:\\Users\\97008\\Documents\\Tencent Files\\970084858\\FileRecv\\dip-class-demos\\testImages\\dragon_Trim.mp4");
	Back_cap.open("C:\\Users\\97008\\Documents\\Tencent Files\\970084858\\FileRecv\\dip-class-demos\\testImages\\bg.mp4");
	while (1) {
		Mat src_dragon, src_bk;
		bool ret = Dragon_cap.read(src_dragon);
		bool ret1 = Back_cap.read(src_bk);
		if (ret&&ret1) {
			Mat frame_dragon, frame_bk;
			frame_dragon = src_dragon(Cut);
			frame_bk = src_bk;
			Mat Mask = Mat::zeros(frame_dragon.size(), CV_8UC1);
			segColor(frame_dragon, &Mask);
			resize(Mask, Mask, Size(272, 480));
			resize(frame_dragon, frame_dragon, Size(272, 480));
			cvtColor(Mask, Mask, COLOR_GRAY2BGR);
			Mat dragon_Img, background, result; 
			Mat mASK;
			bitwise_and(frame_dragon, Mask, dragon_Img);
			bitwise_not(Mask, mASK);
			bitwise_and(frame_bk, mASK, background);
			bitwise_or(dragon_Img, background, result);
			imshow("掩膜", Mask);
			imshow("restult", dragon_Img);
			imshow("背景", background);
			imshow("结果", result);
			waitKey(1);
		}
	}

	//结束计时
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	//显示时间
	cout << "processing time:" << time / 1000 << "ms" << endl;

	//等待键盘响应，按任意键结束程序
	system("pause");
    return 0;
}

