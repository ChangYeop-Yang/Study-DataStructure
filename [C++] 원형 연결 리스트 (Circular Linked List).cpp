#include <iostream>
using namespace std;

/* Typedef */
typedef struct node * mNodePtr;
typedef struct tail * mTailPtr;

/* 원형 연결 리스트 Node Struct */
typedef struct node
{
	int mData; /* Node의 값 */
	mNodePtr mNext; /* Node의 연결 정보 */
} Node;

/* 원형 연결 리스트 Tail Struct */
typedef struct tail
{
	int mSum = 0; /* 연결 된 총 Node의 합 */
	mNodePtr mTail = NULL;
} Tail;

/* 원형 연결 리스트 Function */
void Linsert(mTailPtr mPtr, const int mData)
{
	/* NewNode Create */
	Node * mNewNode = new Node;
	mNewNode->mData = mData;

	if (mPtr->mTail == NULL) 
	{ 
		mPtr->mTail = mNewNode;
		mNewNode->mNext = mNewNode; 
	}
	else
	{
		mNewNode->mNext = mPtr->mTail->mNext;
		mPtr->mTail->mNext = mNewNode;
		mPtr->mTail = mNewNode;
	}

	mPtr->mSum++; /* 연결 된 리스트 총합 증가 */
}
void LinsertFront(mTailPtr mPtr, const int mData)
{
	/* NewNode Create */
	Node * mNewNode = new Node;
	mNewNode->mData = mData;

	if (mPtr->mTail == NULL)
	{
		mPtr->mTail = mNewNode;
		mNewNode->mNext = mNewNode;
	}
	else
	{
		mNewNode->mNext = mPtr->mTail->mNext;
		mPtr->mTail->mNext = mNewNode;
	}

	mPtr->mSum++; /* 연결 된 리스트 총합 증가 */
}
void LprintAll(const mTailPtr mPtr)
{
	cout << "::::: " << "연결 된 리스트의 총합 : " << mPtr->mSum << " :::::" << endl;
	for (int ii = 0; ii < mPtr->mSum; ii++, mPtr->mTail = mPtr->mTail->mNext)
	{
		cout << mPtr->mTail->mData << endl;
	}
}
void Ldelete(mTailPtr mPtr)
{
	Node * mDelNode = mPtr->mTail->mNext;
	int mDelData = mDelNode->mData;

	if (mDelNode == mPtr->mTail)
	{ 
		if (mPtr->mTail == mPtr->mTail->mNext) { mPtr->mTail = NULL; } 
	} 
	else { mPtr->mTail->mNext = mPtr->mTail->mNext->mNext; }

	cout << ":::: " << "삭제 된 노드의 값 : " << mDelData << " ::::" << endl;
	delete (mDelNode);
	mPtr->mSum--;
}

int main(void)
{
	Tail * mTail = new Tail;

	/* Tail Insert */
	Linsert(mTail, 1); Linsert(mTail, 2); Linsert(mTail, 3);
	/* Head Insert */
	LinsertFront(mTail, 4); LinsertFront(mTail, 5); LinsertFront(mTail, 6);

	/* List Print */
	LprintAll(mTail);

	/* List Delete */
	Ldelete(mTail); Ldelete(mTail);

	/* List Print */
	LprintAll(mTail);

	return 0;
}
