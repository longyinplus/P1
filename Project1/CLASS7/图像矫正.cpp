#include <iostream>
#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat src_Img, result, Matrix;
	src_Img = imread("E:\\opencv\\pictures\\lena_turn.jpg");
	int height, weight, x, y, Point_Num, step, start;
	height = src_Img.rows;
	weight = src_Img.cols;
	Point_Num = 0;
	step = 0;
	Point2f src_Point[3], dst_Point[3];

	while (Point_Num < 3) {	//判断有没有找够三个点
		for (x = 0; x < weight; x++) {
			if (src_Img.at<Vec3b>(step, x)[0] < 200 && Point_Num < 3){
				start = x;
				while (src_Img.at<Vec3b>(step, x)[0] != 255) {
					if(x < weight)
						x++;
				}
				src_Point[Point_Num].x = (x + start) / 2;		//找中点
				src_Point[Point_Num].y = step;
				dst_Point[Point_Num].x = 0;
				dst_Point[Point_Num].y = 0;
				Point_Num++;
				break;
			}

		}
		for (x = 0; x < weight; x++) {
			if (src_Img.at<Vec3b>(height - step - 1, x)[0] < 200 && Point_Num < 3) {
				start = x;
				while (src_Img.at<Vec3b>(height - step - 1, x)[0] != 255) {
					if(x < weight)
						x++;
				}

				src_Point[Point_Num].x = (x + start) / 2;
				src_Point[Point_Num].y = height - step - 1;
				dst_Point[Point_Num].x = weight - 1;
				dst_Point[Point_Num].y = height - 1;
				Point_Num++;
				break;
			}
		}
		for (y = 0; y < height; y++) {
			if (src_Img.at<Vec3b>(y, step)[0] < 200 && Point_Num < 3) {
				start = y;
				while (src_Img.at<Vec3b>(y, step)[0] != 255) {
					if(y < height)
						y++;
				}
				src_Point[Point_Num].x = step;
				src_Point[Point_Num].y = (y + start) / 2;
				dst_Point[Point_Num].x = 0;
				dst_Point[Point_Num].y = height;
				Point_Num++;
				break;
			}
		}
		for (y = 0; y < height; y++) {
			if (src_Img.at<Vec3b>(y, weight - step - 1)[0] < 200 && Point_Num < 3) {
				start = y;
				while (src_Img.at<Vec3b>(y, weight - step - 1)[0] != 255) {
					if (y < height)
						y++;
				}
				src_Point[Point_Num].x = weight - step - 1;
				src_Point[Point_Num].y = (y + start) / 2;
				dst_Point[Point_Num].x = weight;
				dst_Point[Point_Num].y = 0;
				Point_Num++;
				break;
			}
		}
		step++;	//图像边缘没找到合适的点, 继续向里找
	}
	cout << src_Point[0] << src_Point[1] << src_Point[2] << endl;
	Matrix = getAffineTransform(src_Point, dst_Point);
	warpAffine(src_Img, result, Matrix, src_Img.size());
	imshow("原图", src_Img);
	imshow("矫正后的图", result);
	waitKey(0);
}