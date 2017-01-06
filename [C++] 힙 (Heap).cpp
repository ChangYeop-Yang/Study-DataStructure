#include <iostream>
#include <algorithm>
using namespace std;

/* Define */
#define HEAP_LEN 100001
#define GetParentIDX(x) x / 2 /* 오른쪽 자식 노드의 인덱스 값 반환 */
#define GetLChildIDX(x) x * 2 /* 왼쪽 자식 노드의 인덱스 값 반환 */
#define GetRChildIDX(x) GetLChildIDX(x) + 1 /* 오른쪽 자식 노드의 인덱스 값 반환 */ 

/* Typedef */
typedef struct heap * HeapPtr;
typedef int PriorityComp(int ch1, int ch2);

/* Struct */
typedef struct heap
{
	int numOfData = 0;
	int heapArr[HEAP_LEN];
	PriorityComp * mCmp;

	heap(PriorityComp mCmpFunction) { mCmp = mCmpFunction; }
} Heap;

/* Function */
int DataPrioirytComp(int ch1, int ch2)
{
	return ch2 - ch1;
}
int GetHiPriChildIDX(HeapPtr mHeap, int idx) /* 두 개의 자식 노드 중 높은 우선수위의 자식 노드 인덱스 값 반환 함수 */
{
	/* 자식 노드가 존재하지 않을 경우 */
	if (GetLChildIDX(idx) > mHeap->numOfData) { return 0; }
	/* 자식 노드가 왼쪽 자식 노드 하나만 존재하는 경우 */
	else if (GetLChildIDX(idx) == mHeap->numOfData) { return GetLChildIDX(idx); }
	/* 자식 도느가 둘 다 존재하는 경우 */
	else { return (mHeap->mCmp(mHeap->heapArr[GetLChildIDX(idx)], mHeap->heapArr[GetRChildIDX(idx)]) < 0 ? GetRChildIDX(idx) : GetLChildIDX(idx)); }
}
void HInsert(HeapPtr mHeap, int mData)
{
	int idx = mHeap->numOfData + 1;

	/* 새 노드가 저장 될 위치가 루트 노드의 위치가 아니라면 While문 반복 */
	while (idx != 1)
	{
		/* 새 노드와 부모 노드의 우선순위 비교 */
		if (mHeap->mCmp(mData, mHeap->heapArr[GetParentIDX(idx)]) > 0)
		{
			/* 새 노드의 우선순위가 높다면 부모 노드를 한 레벨 내린다. */
			mHeap->heapArr[idx] = mHeap->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx); /* 새노드를 한레벨 올린다. 인덱스 값만 갱신 */
		}
		else { break; }
	}

	mHeap->heapArr[idx] = mData;
	mHeap->numOfData++;
}
int HDelete(HeapPtr mHeap)
{
	int retData = (mHeap->heapArr[1]); /* 반환을 위해서 삭제할 데이터의 저장 */
	int lastElem = mHeap->heapArr[mHeap->numOfData]; /* 힙의 마지막 노드 저장 */

	int parentIdx = 1; /* Root노드가 위치해야 할 인덱스 값 저장 */
	int childIdx;

	/* 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작 */
	while (childIdx = GetHiPriChildIDX(mHeap, parentIdx))
	{
		/* 마지막 노드가 우선순위가 높은 경우 탈출 */
		if (mHeap->mCmp(lastElem, mHeap->heapArr[childIdx]) >= 0) { break; }

		/* 마지막 노드보다 우선순위가 높으므로 비교대상 노드의 위치를 한 레벨 올린다. */
		mHeap->heapArr[parentIdx] = mHeap->heapArr[childIdx];
		parentIdx = childIdx; /* 마지막 노드가 저장 될 위치정보를 한 레벨 내린다. */
	}

	/* 마지막 노드 최종 저장 */
	mHeap->heapArr[parentIdx] = lastElem;
	mHeap->numOfData--;
	return retData;
}
void HeapSort(PriorityComp Pc, int * mArr, int mSize)
{
	/* Heap */
	Heap mHeap(Pc);

	/* Heap Insert */
	for (int ii = 0; ii < mSize; ii++) { HInsert(&mHeap, mArr[ii]); }

	/* Heap Delete */
	for (int ii = 0; ii < mSize; ii++) { *(mArr + ii) = HDelete(&mHeap); }

	/* Sorting Print */
	for (int ii = 0; ii < mSize; ii++) { cout << *(mArr + ii) << endl; }
}

int main(void)
{
	Heap mHeap(DataPrioirytComp);
	return 0;
}
