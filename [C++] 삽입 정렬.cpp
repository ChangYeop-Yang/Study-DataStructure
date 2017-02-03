/* 삽입 정렬 */
void insertSort(int * mArr, int mLength)
{
	int mTemp = 0;
	int mInsData = 0;

	for (int ii = 1, jj = 0; ii < mLength; ii++)
	{
		mInsData = mArr[ii];
		for (jj = ii - 1; jj >= 0; jj--)
		{
			if (mArr[jj] < mInsData) /* 데이터간 연산 비교 구문 */
				mArr[jj + 1] = *(mArr + jj); /* 비교 대상을 한 칸 뒤로 밀기 */
			else  
				break; /* 삽입위치를 찾았으므로 탈출 */
		}

		mArr[jj + 1] = mInsData;
	} printArray(mArr, mLength);
}
