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
	//�趨����ɫ��HSV��Χ
	double i_minH = 0;
	double i_maxH = 20;
	double i_minS = 34;
	double i_maxS = 255;

	double i_minV = 45;
	double i_maxV = 255;
	namedWindow("ÿͼ���ݹ�����");
	createTrackbar("ĥƤǿ������", "ÿͼ���ݹ�����", &block_size, 49, Trackbar);
	cap.open(0);
	if (!cap.isOpened()) {
		cout << "����ͷ����ʧ��" << endl;
	}
	while (1) {
		ret = cap.read(frame);
		if (ret) {
			Mat Face, fACE, result;
			cvtColor(frame, HSV_Frame, CV_BGR2HSV);
			inRange(HSV_Frame, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), Mask_Frame);
			frame.copyTo(Face, Mask_Frame); //��ȥ��������, 
			if(block_size % 2)
				medianBlur(Face, Face, block_size);   //��������ĥƤ
			else
				medianBlur(Face, Face, block_size + 1);
			imshow("þͼ����", Face);
			bitwise_not(Mask_Frame, mASK_fRAME);  //������ȥ������Ĥ
			frame.copyTo(fACE, mASK_fRAME);		  //����ȥ������ͼ��
			bitwise_or(fACE, Face, result);
			imshow("��ͼ����", result);
			key = waitKey(10);
			if (key == ' ')
				break;
		}
	}
}