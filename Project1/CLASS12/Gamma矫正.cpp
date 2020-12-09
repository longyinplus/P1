#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void Gamma(float* A, float Lammda)
{
	for (int n = 0; n < 256; n++) {
		A[n] = pow(n / 255.0, Lammda);
	}
}

int main()
{
	Mat src, result;
	float F[256], Lammda = 0.5 ;
	src = imread("E:\\opencv\\pictures\\Gamma.jpg");
	int wight = src.cols, y, x;
	int heigth = src.rows;

	//生成映射表,然后进行Gamma处理
	Gamma(F, Lammda);
	//再还原到0-255
	src.copyTo(result);
	for (y = 0; y < heigth; y++) {
		for (x = 0; x < wight; x++) {
			result.at<Vec3b>(y, x)[0] = ceil(F[result.at<Vec3b>(y, x)[0]] * 255.0);
			result.at<Vec3b>(y, x)[1] = ceil(F[result.at<Vec3b>(y, x)[1]] * 255.0);
			result.at<Vec3b>(y, x)[2] = ceil(F[result.at<Vec3b>(y, x)[2]] * 255.0);
		}
	}
	imshow("Killer", src);
	imshow("平静的生活", result);
	waitKey(0);
	return 0;
}