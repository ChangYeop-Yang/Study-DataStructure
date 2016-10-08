#include <iostream> 
#include <queue>
#define SWAP(X, Y, Z) (Z=X); (X=Y); (Y=Z);
#define INF 1000001
#define BUCKET 10
using namespace std;

inline void printArray(int * mArr, int mLength)
{
	for (int ii = 0; ii < mLength; ii++)
		cout << mArr[ii] << endl;

	cout << endl;
}

/* 선택 정렬 */
void selectionSort(int * mArr, int mLength)
{
	int mTemp = 0;
	int mIdx = 0;

	for (int ii = 0; ii < mLength - 1; ii++)
	{
		mIdx = ii;
		for (int jj = ii + 1; jj < mLength; jj++) /* 최솟값 탐색 반복문 */
		{ 
			if (mArr[jj] < mArr[mIdx]) /* 선택 정렬 비교 연산 */
				mIdx = jj;
		}

		SWAP(mArr[ii], mArr[mIdx], mTemp);
	} printArray(mArr, mLength);
}

/* 버블 정렬 */
void BubbleSort(int * mArr, int mLength)
{
	int mTemp = 0;

	for (int ii = 0; ii < mLength - 1; ii++)
	{
		for (int jj = 0; jj < (mLength - ii) - 1; jj++)
		{
			if (mArr[jj] > mArr[jj + 1])
				SWAP(mArr[jj], mArr[jj + 1], mTemp);
		}
	} printArray(mArr, mLength);
}

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

void mergerSort(int * mArr, int first, int last)
{
	int middle;

	if (first < last) /* First가 작다는 Last보다 작은 것은 더 분할을 할 수 있다는 뜻이다. */
	{
		middle = (first + last) / 2; /* 중간 지점을 계산한다. */

		/* 둘로 나눠서 각각을 정렬한다. */
		mergerSort(mArr, first, middle); /* First ~ Middle에 위치한 데이터 정렬 */
		mergerSort(mArr, middle + 1, last); /* Middle+1 ~ Last에 위치한 데이터 정렬 */
		
		/* 정렬된 두 배열을 병합한다. */
		merger(mArr, first, middle, last); /* 정렬 된 두 배열을 병합한다. */
	}
}

/* 퀵 정렬 */
void QuickSort(int * mArr, int left, int right)
{
	int pivot = mArr[(left + right) / 2]; /* 중심축 */
	int mLeft = left; /* 정렬 대상의 가장 왼쪽 지점 */
	int mRight = right; /* 정렬 대상의 가장 오른쪽 지점 */
	int mTemp = 0;

	while (mLeft <= mRight) /* mLeft와 mRight가 교차하지 않을 때 경우까지 반복한다. */
	{
		while (mArr[mLeft] > pivot) { ++mLeft; } /* pivot 보다 큰 값을 찾는 경우 */
		while (mArr[mRight] < pivot) { --mRight; } /* pivot 보다 작은 값을 찾는 경우 */

		if (mLeft <= mRight) /* mLeft 보다 mRight가 값이 크거나 같은 경우 */
		{
			SWAP(mArr[mLeft], mArr[mRight], mTemp); /* mLeft와 mRight 값을 교환한다. */
			++mLeft, --mRight; /* mLeft 증가, mRight 감소 */
		}
	}

	if (left < mRight) { QuickSort(mArr, left, mRight); }
	if (mLeft < right) { QuickSort(mArr, mLeft, right); }
}

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

int main(void)
{
	int mArr[10] = { 3, 5, 6, 1, 2, 4, 7, 8, 10, 9 };
	int mSize = sizeof(mArr) / sizeof(int);

	/* 선택 정렬 (Selection Sort) */
	cout << ":::: Selection Sort ::::" << endl;
	selectionSort(mArr, mSize);

	/* 삽입 정렬 (Insert Sort) */
	cout << ":::: Insert Sort ::::" << endl;
	insertSort(mArr, mSize);

	/* 버블 정렬 (Bubble Sort) */
	cout << ":::: Bubble Sort ::::" << endl;
	BubbleSort(mArr, mSize);

	/* 퀵 정렬 (Quick Sort) */
	cout << ":::: Quick Sort ::::" << endl;
	QuickSort(mArr, 0, mSize - 1);
	printArray(mArr, mSize);

	/* 기수 정렬 (Radix Sort) */
	cout << ":::: Radix Sort ::::" << endl;
	RadixSort(mArr, mSize, 2);

	/* 합병 정렬 (Meger Sort) */
	cout << ":::: Metger Sort ::::" << endl;
	mergerSort(mArr, 0, mSize - 1);
	printArray(mArr, mSize);

	return 0;
}
