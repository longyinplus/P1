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
	//归一化, 然后放到数组里
	for (y = 0; y < heigth; y++) {
		for (x = 0; x < wight; x++) {
			B[src.at<Vec3b>(y, x)[0]] = (float)src.at<Vec3b>(y, x)[0] / 255.0;
			G[src.at<Vec3b>(y, x)[1]] = (float)src.at<Vec3b>(y, x)[1] / 255.0;
			R[src.at<Vec3b>(y, x)[2]] = (float)src.at<Vec3b>(y, x)[2] / 255.0;
		}
	}
	//进行Gamma处理
	Gamma(B, Lammda);
	Gamma(G, Lammda);
	Gamma(R, Lammda);
	//再还原到0-255
	src.copyTo(result);
	for (y = 0; y < heigth; y++) {
		for (x = 0; x < wight; x++) {
			result.at<Vec3b>(y, x)[0] = ceil(B[result.at<Vec3b>(y, x)[0]] * 255.0);
			result.at<Vec3b>(y, x)[1] = ceil(G[result.at<Vec3b>(y, x)[1]] * 255.0);
			result.at<Vec3b>(y, x)[2] = ceil(R[result.at<Vec3b>(y, x)[2]] * 255.0);
		}
	}
	imshow("Killer", src);
	imshow("平静的生活", result);
	waitKey(0);
	return 0;
}