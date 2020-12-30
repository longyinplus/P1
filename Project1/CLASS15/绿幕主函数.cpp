// dip-class-demos.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <opencv.hpp>
#include "green_funtions.h"

using namespace cv;
using namespace std;

int main()
{
	//��ʼ��ʱ
	double start = static_cast<double>(cvGetTickCount());
	VideoCapture Dragon_cap;
	VideoCapture Back_cap;
	Rect Cut;		//�����ѷ��˵Ķ���logoȥ��
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
			imshow("��Ĥ", Mask);
			imshow("restult", dragon_Img);
			imshow("����", background);
			imshow("���", result);
			waitKey(1);
		}
	}

	//������ʱ
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	//��ʾʱ��
	cout << "processing time:" << time / 1000 << "ms" << endl;

	//�ȴ�������Ӧ�����������������
	system("pause");
    return 0;
}

