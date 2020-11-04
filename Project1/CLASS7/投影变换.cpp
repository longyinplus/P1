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
		Point2f(150, 150), Point2f(150, 300), Point2f(350, 300), Point2f(350, 150)
	};
	const Point2f dst_pt[] = {
		Point2f(200, 150), Point2f(200, 300), Point2f(340, 270), Point2f(340, 180)
	};
	Matrix = getPerspectiveTransform(src_pt, dst_pt);
	cout << Matrix << endl;
	cv::warpPerspective(src_Img, result_Img, Matrix, src_Img.size());

	cv::imshow("°¢°Í°¢°Í", src_Img);
	cv::imshow("Ðý×ª", result_Img);
	cv::waitKey(0);
}