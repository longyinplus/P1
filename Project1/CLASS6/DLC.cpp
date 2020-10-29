#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int block_size =  5;
void Trackbar(int a, void* b)
{
	return;
}
int main()
{
	VideoCapture cap;
	bool ret;
	char key;
	Mat frame, HSV_Frame, Mask_Frame, mASK_fRAME;
	//设定侦测肤色的HSV范围
	double i_minH = 0;
	double i_maxH = 20;
	double i_minS = 34;
	double i_maxS = 255;

	double i_minV = 45;
	double i_maxV = 255;
	namedWindow("每图休休公举栏");
	createTrackbar("磨皮强度设置", "每图休休公举栏", &block_size, 49, Trackbar);
	cap.open(0);
	if (!cap.isOpened()) {
		cout << "摄像头启动失败" << endl;
	}
	while (1) {
		ret = cap.read(frame);
		if (ret) {
			Mat Face, fACE, result;
			cvtColor(frame, HSV_Frame, CV_BGR2HSV);
			inRange(HSV_Frame, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), Mask_Frame);
			frame.copyTo(Face, Mask_Frame); //滤去其他部分, 
			if(block_size % 2)
				medianBlur(Face, Face, block_size);   //对脸进行磨皮
			else
				medianBlur(Face, Face, block_size + 1);
			imshow("镁图锈锈", Face);
			bitwise_not(Mask_Frame, mASK_fRAME);  //制作除去脸的掩膜
			frame.copyTo(fACE, mASK_fRAME);		  //生成去掉脸的图像
			bitwise_or(fACE, Face, result);
			imshow("媚图嗅嗅", result);
			key = waitKey(10);
			if (key == ' ')
				break;
		}
	}
}