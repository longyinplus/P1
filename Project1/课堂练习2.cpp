#include<iostream>
#include<opencv2\opencv.hpp>
using namespace cv;
int main()
{
	Mat srcImg, DeepCopy, ShallowCopy;
	int height, weight, x, y, flag = 0;
	uchar key;
	uchar* data;
	srcImg = imread("E:\\opencv\\pictures\\lena.jpg");
	ShallowCopy = srcImg;
	height = srcImg.rows;
	weight = srcImg.cols * srcImg.channels();
	namedWindow("深复制", CV_WINDOW_NORMAL);
	while (1) {
		srcImg.copyTo(DeepCopy);
		for (y = 0; y < height; y++) {
			data = DeepCopy.ptr<uchar>(y);
			for (x = 0; x < weight; x++) {
				switch (x % 3)
				{
				case 0:
					if(flag == 0)
						data[x] = 0;
					break;
				case 1:
					if (flag == 1)
						data[x] = 0;
				case 2:
					if (flag == 2)
						data[x] = 0;
				default:
					break;
				}
			}
		}
		imshow("原图", srcImg);
		imshow("浅复制", ShallowCopy);
		imshow("深复制", DeepCopy);
		key = waitKey(100);
		flag++;
		if (flag == 3)
			flag = 0;
		if (key == 'q')
			break;
	}
}