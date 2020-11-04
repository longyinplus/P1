#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src_Img, result_Img, Matrix;
	float angle = -10.0, scale = 1;
	src_Img = imread("E:\\opencv\\pictures\\Jotara.png");
	if (src_Img.empty()) {
		cout << "Í¼Æ¬ÊÇ¿ÕßÕ" << endl;
		return -1;
	}
	Point2f center(src_Img.cols * 0.5, src_Img.rows * 0.5);
	Matrix = getRotationMatrix2D(center, angle, scale);
	warpAffine(src_Img, result_Img, Matrix, src_Img.size());

	imshow("Ô­Í¼Ïñ", src_Img);
	imshow("Ðý×ª", result_Img);
	waitKey(0);
}