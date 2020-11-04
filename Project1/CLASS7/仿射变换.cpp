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
	const Point2f src_pt[] = {
		Point2f(200, 200), Point2f(250, 200), Point2f(200, 100)
	};
	const Point2f dst_pt[] = {
		Point2f(300, 100), Point2f(300, 50), Point2f(200, 100)
	};
	Matrix = getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(src_Img, result_Img, Matrix, src_Img.size());

	cv::imshow("°¢°Í°¢°Í", src_Img);
	cv::imshow("Ðý×ª", result_Img);
	cv::waitKey(0);
}