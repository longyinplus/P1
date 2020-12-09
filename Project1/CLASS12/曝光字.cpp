#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;
float Lammda = 0.5;
int Track_Flag = 1;
void Gamma(float* Input, float* Output, float Lammda)
{
	for (int n = 0; n < 255; n++) {
		Output[n] = pow(Input[n], Lammda);
	}
}

void GetLammda(int a, void* dat)
{
	Lammda = (float)a / 100.0;
	Track_Flag = 1;
}

int main()
{
	Mat src;
	float B_src[256], G_src[256], R_src[256];
	src = imread("E:\\opencv\\pictures\\Gamma_word.jpg");
	int wight = src.cols, y, x, Track = 50;
	int heigth = src.rows;
	//归一化, 然后放到数组里
	for (y = 0; y < heigth; y++) {
		for (x = 0; x < wight; x++) { 
			B_src[src.at<Vec3b>(y, x)[0]] = (float)src.at<Vec3b>(y, x)[0] / 255.0;
			G_src[src.at<Vec3b>(y, x)[1]] = (float)src.at<Vec3b>(y, x)[1] / 255.0;
			R_src[src.at<Vec3b>(y, x)[2]] = (float)src.at<Vec3b>(y, x)[2] / 255.0;

		}
	}
	namedWindow("Tool");
	createTrackbar("λ", "Tool", &Track, 200, GetLammda);
	imshow("Killer", src);
	while (1) {
		if (Track_Flag) {
			Mat result;
			float B[256], G[256], R[256];
			//进行Gamma处理
			Gamma(B_src, B, Lammda);
			Gamma(G_src, G, Lammda);
			Gamma(R_src, R, Lammda);
			//再还原到0-255
			src.copyTo(result);
			for (y = 0; y < heigth; y++) {
				for (x = 0; x < wight; x++) {
					result.at<Vec3b>(y, x)[0] = ceil(B[result.at<Vec3b>(y, x)[0]] * 255.0);
					result.at<Vec3b>(y, x)[1] = ceil(G[result.at<Vec3b>(y, x)[1]] * 255.0);
					result.at<Vec3b>(y, x)[2] = ceil(R[result.at<Vec3b>(y, x)[2]] * 255.0);
				}
			}
			imshow("平静的生活", result);
			Track_Flag = 0;
		} 
		char key = waitKey(50);
		if (key == ' ')
			break;
	}
	waitKey(0);
	return 0;
}