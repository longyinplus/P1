#include <opencv2/opencv.hpp> 
#include <iostream> 
#define Num 100
int a[Num] = { 0 };
using namespace cv; 

void Find_Su()
{
	int sum, i;
	for (i = 2; i < sqrt(Num); i++) {
		sum = i;
		if (a[sum] == 0) {
			while (sum < Num) {
				sum += i;
				if (sum < Num)
					a[sum] = 1;
			}
		}
	}
	for (i = 2; i < Num; i++) {
		if (a[i] == 0)
			printf("%d\r\n", i);
	}
}

int main() {
	Find_Su();
	return 0;
}
