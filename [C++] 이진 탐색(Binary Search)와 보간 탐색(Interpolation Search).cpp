#include <iostream>
using namespace std;

int BinarySearch(int * mArr, int start, int end, int target)
{
	int mid = 0; /* 중간값을 저장하는 변수 */

	if (start > end) { return EOF; }

	mid = (start + end) / 2; /* 배열의 중간 값 계산 */

	if (mArr[mid] == target) { return mid; }
	else if (mArr[mid] > target) { return BinarySearch(mArr, start, mid-1, target); } /* 찾고자 하는 값이 작은 경우 */
	else { return BinarySearch(mArr, mid + 1, end, target); } /* 찾고자 하는 값이 큰 경우 */
}

int InterpolSerarch(int * mArr, int start, int end, int target)
{
	int mid = 0; /* 중간값을 저장하는 변수 */

	if (mArr[start] > target || mArr[end] < target) { return EOF; }
	
	mid = ((double)(target - mArr[start]) / (mArr[end] - mArr[start]) * (end - start)) + start;

	if (mArr[mid] == target) { return mid; }
	else if (mArr[mid] > target) { return InterpolSerarch(mArr, start, mid - 1, target); }
	else { return InterpolSerarch(mArr, mid + 1, end, target); }
}

int main(void)
{
	int mArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << BinarySearch(mArr, 0, 9, 4) << endl;

	cout << InterpolSerarch(mArr, 0, 9, 6) << endl;

	return 0;
}
