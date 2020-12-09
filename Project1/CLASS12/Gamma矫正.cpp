#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void Gamma(float* A, float Lammda)
{
	for (int n = 0; n < 255; n++) {
		A[n] = pow(A[n], Lammda);
	}
}

int main()
{
	Mat src, result;
	float B[256], G[256], R[256], Lammda = 0.5 ;
	src = imread("E:\\opencv\\pictures\\Gamma.jpg");
	int wight = src.cols, y, x;
	int heigth = src.rows;
	//��һ��, Ȼ��ŵ�������
	for (y = 0; y < heigth; y++) {
		for (x = 0; x < wight; x++) {
			B[src.at<Vec3b>(y, x)[0]] = (float)src.at<Vec3b>(y, x)[0] / 255.0;
			G[src.at<Vec3b>(y, x)[1]] = (float)src.at<Vec3b>(y, x)[1] / 255.0;
			R[src.at<Vec3b>(y, x)[2]] = (float)src.at<Vec3b>(y, x)[2] / 255.0;
		}
	}
	//����Gamma����
	Gamma(B, Lammda);
	Gamma(G, Lammda);
	Gamma(R, Lammda);
	//�ٻ�ԭ��0-255
	src.copyTo(result);
	for (y = 0; y < heigth; y++) {
		for (x = 0; x < wight; x++) {
			result.at<Vec3b>(y, x)[0] = ceil(B[result.at<Vec3b>(y, x)[0]] * 255.0);
			result.at<Vec3b>(y, x)[1] = ceil(G[result.at<Vec3b>(y, x)[1]] * 255.0);
			result.at<Vec3b>(y, x)[2] = ceil(R[result.at<Vec3b>(y, x)[2]] * 255.0);
		}
	}
	imshow("Killer", src);
	imshow("ƽ��������", result);
	waitKey(0);
	return 0;
}