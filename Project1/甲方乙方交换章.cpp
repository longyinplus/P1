#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;
float Lammda = 0.5;
int Track_Flag = 1;
void Gamma(float* A, float Lammda)
{
	for (int n = 0; n < 256; n++) {
		A[n] = pow((float)n / 255.0, Lammda);
	}
}

void GetLammda(int a, void* dat)
{
	Lammda = (float)a / 100.0;
	Track_Flag = 1;
}

void GetThreshold(int a, void* dat)
{
	Track_Flag = 1;
}

int main()
{
	Mat src;
	float B_src[256], G_src[256], R_src[256];
	src = imread("E:\\opencv\\pictures\\Trash.jpg");
	int wight = src.cols, y, x, Track = 50, Threshold = 100;
	int heigth = src.rows;
	int flag = 0;
	//归一化, 然后放到数组里
	namedWindow("Tool");
	namedWindow("平静的生活", WINDOW_NORMAL);
	namedWindow("平静的生活2", WINDOW_NORMAL);
	namedWindow("平静的生活Red", WINDOW_NORMAL);
	createTrackbar("λ", "Tool", &Track, 500, GetLammda);
	createTrackbar("Threshold", "Tool", &Threshold, 255, GetThreshold);
	imshow("Killer", src);
	while (1) {
		if (Track_Flag) {
			Mat Big_result, Thr_result;
			vector<Mat> channel;
			float F[256];
			//进行Gamma处理
			Gamma(F, Lammda);
			//再还原到0-255
			src.copyTo(Big_result);
			for (y = 0; y < heigth; y++) {
				for (x = 0; x < wight; x++) {
					Big_result.at<Vec3b>(y, x)[2] = ceil(F[Big_result.at<Vec3b>(y, x)[2]] * 255.0);
				}
			}
			split(Big_result, channel);
			threshold(channel[2], Thr_result, Threshold, 255, 0);
			imshow("平静的生活Red", channel[2]);
			imshow("平静的生活", Big_result);
			imshow("平静的生活2", Thr_result);
			Track_Flag = 0;
		}
		char key = waitKey(50);
		if (key == ' ')
			break;
	}
	waitKey(0);
	return 0;
}