#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src_Img, Gray_Img, IO_Img, kernel, OK_Img, Labels, Stats, Centroids;
	Size size;
	Point Start, End;
	int  Count = 0;
	src_Img = imread("E:\\opencv\\pictures\\CLASS5-3.png");
	cvtColor(src_Img, Gray_Img, CV_RGB2GRAY);
	threshold(Gray_Img, IO_Img, 100, 255, THRESH_BINARY_INV);
	imshow("��ֵ�����", IO_Img);
	size.height = 21;
	size.width = 21;
	kernel = getStructuringElement(MORPH_RECT, size);
	morphologyEx(IO_Img, OK_Img, MORPH_OPEN, kernel);
	imshow("Ԥ������", OK_Img);	//������ȥ����

	connectedComponentsWithStats(OK_Img, Labels, Stats, Centroids, 8, CV_32S);
	for (int a = 0; a < Stats.rows; a++) {
		long* data = Stats.ptr<long>(a);
		if (data[4] < 10000) {		//̫�����ͨ��϶��Ǳ���
			Count++;
			Start.x = data[0];
			Start.y = data[1];
			End.x = Start.x + data[2];
			End.y = Start.y + data[3];
			rectangle(src_Img, Start, End, CV_RGB(72, 142, 62), 3);
		}
	}
	imshow("��ǽ��", src_Img);
	cout << "�������Ϊ:" << Count << endl;
	waitKey(0);

	return 0;
}