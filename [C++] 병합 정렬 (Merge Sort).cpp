/* 합병 정렬 */
void merger(int * mArr, int first, int mid, int last)
{
	/* 각각 병합할 두 영역의 첫 번째 위치 정보가 담긴 변수 */
	int fIdx = first; /* 배열의 앞쪽 영역을 가리키는 변수 */
	int rIdx = mid + 1; /* 배열의 뒤쪽 영역을 가리키는 변수 */

	int sIdx = first;
	int ii = 0;

	/* 병합 한 결과를 담을 배열을 생성한다. */
	int * mSumArr = new int[last + 1];

	/* 병합 할 두 영역의 데이터들을 비교하여, 정렬 순서 대로 임시 생성 한 배열에 하나씩 옮겨 담는다. */
	while (fIdx <= mid && rIdx <= last) /* 배열의 앞쪽 영역에도, 배열의 뒤쪽 영역에도 비교의 대상이 남아있는 상황에서 반복조건이 '참'임을 의미한다. */
	{
		if (mArr[fIdx] <= mArr[rIdx]) 
			mSumArr[sIdx] = mArr[fIdx++]; /* 배열의 앞부분이 모두 임시 생성 배열에 옮겨 졌다면 배열의 뒷부분에 남은 데이터들을 그대로 옮긴다. */
		else 
			mSumArr[sIdx] = mArr[rIdx++]; /* 배열의 뒷부분이 모두 임시 생성 배열에 옮겨졌다면 배열의 앞부분에 남은 데이터들을 그대로 옮긴다. */

		sIdx++;
	}

	if (fIdx > mid) /* 배열의 앞부분이 모두 임시 생성 한 배열에 옮겨졌다면, 배열의 뒷부분에 남은 데이터들을 그대로 옮긴다. */
	{
		for (ii = rIdx; ii <= last; ii++, sIdx++)
			mSumArr[sIdx] = mArr[ii];
	}
	else /* 배열의 뒷부분이 모두 임시 생성 한 배열에 그대로 옮겨졌다면, 배열의 앞부분에 남은 데이터들을 그대로 옮긴다. */
	{
		for (ii = fIdx; ii <= mid; ii++, sIdx++)
			mSumArr[sIdx] = mArr[ii];
	}

	for (ii = first; ii <= last; ii++)
		mArr[ii] = mSumArr[ii];

	delete[] mSumArr;
}
