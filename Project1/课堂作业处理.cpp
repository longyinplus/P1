#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src_Img, result_Img, Matrix;
	float angle = -10.0, scale = 1;
	int wight, height;
	src_Img = imread("E:\\opencv\\pictures\\Buliding_Class.jpg");
	if (src_Img.empty()) {
		cout << "ͼƬ�ǿ���" << endl;
		return -1;
	}
	wight = src_Img.cols;
	height = src_Img.rows;
	const Point2f src_pt[] = {
		Point2f(0, 0), Point2f(0, 3644), Point2f(2866, 3807), Point2f(2909, 0)
	};
	const Point2f dst_pt[] = {
		Point2f(0, 0), Point2f(0, height), Point2f(wight, height), Point2f(wight, 0)
	};
	Matrix = getPerspectiveTransform(src_pt, dst_pt);
	cout << Matrix << endl;
	cv::warpPerspective(src_Img, result_Img, Matrix, src_Img.size());
	namedWindow("��ת", WINDOW_NORMAL);
	cv::imshow("���Ͱ���", src_Img);
	cv::imshow("��ת", result_Img);
	cv::waitKey(0);
	imwrite("result.jpg", result_Img);

}