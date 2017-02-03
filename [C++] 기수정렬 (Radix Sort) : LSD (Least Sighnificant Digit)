/* 기수 정렬 */
void RadixSort(int * mArr, int num, int mMaxLength)
{
	queue<int> mQueue[BUCKET];

	int divfac = 1;
	int radix = 0;

	/* 가장 긴 데이터의 길이만큼 반복 */
	for (int pos = 0; pos < mMaxLength; pos++)
	{
		/* 정렬대상의 수 만큼 반복 */
		for (int di = 0; di < num; di++)
		{
			/* N번째 자리의 숫자 추출 */
			radix = (mArr[di] / divfac) % 10;
			
			/* 추출한 숫자를 근거로 버킷에 데이터 저장 */
			mQueue[radix].push(mArr[di]);
		}

		/* 버킷 수 만큼 반복 */
		for (int bi = 0, di = 0; bi < BUCKET; bi++)
		{
			/* 버킷에 저장된 것 순서대로 다 꺼내서 다시 Arr에 저장 */
			while (mQueue[bi].empty() == false)
			{
				mArr[di++] = mQueue[bi].front();
				mQueue[bi].pop();
			}
		}

		/* N번째 자리의 숫자 추출을 위한 피제수의 증가 */
		divfac *= 10;
	}

	printArray(mArr, num);
}
