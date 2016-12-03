#include <iostream>
#include <cstring>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef struct node * DequeNode;
typedef struct head * DequeHead;

/* Deque Data Node */
typedef struct node
{
	int mData; /* 자료 */
	DequeNode mNext; /* 다음 노드 */
	DequeNode mPrev; /* 이전 노드 */
} Node;

/* Deque Head Node */
typedef struct head
{
	int mSize = 0;
	DequeNode mHead; /* 앞 노드 */
	DequeNode mTail; /* 뒷 노드 */
} Head;

/* Function ADT */
int DQEmpty(DequeHead pdeq); /* 덱이 비어있는지 확인하는 함수 */
void DQAddFirst(DequeHead pdeq, int mData); /* 덱의 머리에 데이터 추가 함수 */
void DQAddLast(DequeHead pdeq, int mData); /* 덱의 꼬리에 데이터 추가 함수 */
int DQRemoveFirst(DequeHead pdeq); /* 덱의 머리에 데이터 삭제 함수 */
int DQRemoveLast(DequeHead pdeq); /* 덱의 꼬리에 데이터 삭제 함수 */
int DQPickFirst(DequeHead pdeq); /* 덱의 머리에 데이터 참조 */
int DQPickLast(DequeHead pdeq); /* 덱의 꼬리에 데이터 참조 */

int main(void)
{
	DequeHead mDeque = new Head;
	mDeque->mHead = mDeque->mTail = NULL;

	int mNum = 0;
	cin >> mNum;

	for (int ii = 0; ii < mNum; ii++)
	{
		char mChar[25] = { 0, };
		cin >> mChar;
		
		if (strcmp(mChar, "push_front") == 0) 
		{
			int mTemp = 0; cin >> mTemp;
			DQAddFirst(mDeque, mTemp);
		}
		else if (strcmp(mChar, "push_back") == 0)
		{
			int mTemp = 0; cin >> mTemp;
			DQAddLast(mDeque, mTemp);
		}
		else if (strcmp(mChar, "pop_front") == 0) { cout << DQRemoveFirst(mDeque) << endl; }
		else if (strcmp(mChar, "pop_back") == 0) { cout << DQRemoveLast(mDeque) << endl; }
		else if (strcmp(mChar, "size") == 0) { cout << mDeque->mSize << endl; }
		else if (strcmp(mChar, "empty") == 0) { cout << DQEmpty(mDeque) << endl; }
		else if (strcmp(mChar, "front") == 0) { cout << DQPickFirst(mDeque) << endl; }
		else if (strcmp(mChar, "back") == 0) { cout << DQPickLast(mDeque) << endl; }
	}

	return 0;
}

/* 덱이 비어있는 상태를 확인하는 함수 */
int DQEmpty(DequeHead pdeq) { return (pdeq->mHead == NULL ? TRUE : FALSE); }
/* 덱의 머리부분에 데이터를 추가하는 함수 */
void DQAddFirst(DequeHead pdeq, int mData)
{
	/* Deque의 새로운 노드 생성 */
	DequeNode newNode = new Node;
	newNode->mData = mData;

	newNode->mNext = pdeq->mHead;

	DQEmpty(pdeq) ? pdeq->mTail = newNode : pdeq->mHead->mPrev = newNode;
	
	newNode->mPrev = NULL;
	pdeq->mHead = newNode;
	pdeq->mSize++;
}
void DQAddLast(DequeHead pdeq, int mData)
{
	/* Deque의 새로운 노드 생성 */
	DequeNode newNode = new Node;
	newNode->mData = mData;

	newNode->mPrev = pdeq->mTail;

	DQEmpty(pdeq) ? pdeq->mHead = newNode : pdeq->mTail->mNext = newNode;

	newNode->mNext = NULL;
	pdeq->mTail = newNode;
	pdeq->mSize++;
}
int DQRemoveFirst(DequeHead pdeq)
{
	DequeNode mRnode = pdeq->mHead;
	int mData = 0;

	if (DQEmpty(pdeq)) { return -1; }
	mData = pdeq->mHead->mData;

	pdeq->mHead = pdeq->mHead->mNext;
	free(mRnode);

	pdeq->mHead == NULL ? pdeq->mTail = NULL : pdeq->mHead->mPrev = NULL;
	pdeq->mSize--;

	return mData;
}
int DQRemoveLast(DequeHead pdeq)
{
	DequeNode mLnode = pdeq->mTail;
	int mData = 0;

	if (DQEmpty(pdeq)) { return -1; }
	mData = pdeq->mTail->mData;

	pdeq->mTail = pdeq->mTail->mPrev;
	free(mLnode);

	pdeq->mTail == NULL ? pdeq->mHead = NULL : pdeq->mTail->mNext = NULL;
	pdeq->mSize--;

	return mData;
}
int DQPickFirst(DequeHead pdeq) { return (DQEmpty(pdeq) ? -1 : pdeq->mHead->mData); }
int DQPickLast(DequeHead pdeq) { return (DQEmpty(pdeq) ? -1 : pdeq->mTail->mData); }
