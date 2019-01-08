/* 퀵 정렬 */
void QuickSort(int * mArr, int left, int right)
{
	int pivot = mArr[(left + right) / 2]; /* 중심축 */
	int mLeft = left; /* 정렬 대상의 가장 왼쪽 지점 */
	int mRight = right; /* 정렬 대상의 가장 오른쪽 지점 */
	int mTemp = 0;

	while (mLeft <= mRight) /* mLeft와 mRight가 교차하지 않을 때 경우까지 반복한다. */
	{
		while (mArr[mLeft] < pivot) { ++mLeft; } /* pivot 보다 작은 값을 찾는 경우 */
		while (mArr[mRight] > pivot) { --mRight; } /* pivot 보다 큰 값을 찾는 경우 */

		if (mLeft <= mRight) /* mLeft 보다 mRight가 값이 크거나 같은 경우 */
		{
			SWAP(mArr[mLeft], mArr[mRight], mTemp); /* mLeft와 mRight 값을 교환한다. */
			++mLeft, --mRight; /* mLeft 증가, mRight 감소 */
		}
	}

	if (left < mRight) { QuickSort(mArr, left, mRight); }
	if (mLeft < right) { QuickSort(mArr, mLeft, right); }
}
