#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* Typedef */
typedef struct tree * mTreePtr;
typedef void mMyFunc (mTreePtr mTree);

/* Struct */
typedef struct tree
{
	char mData;
	mTreePtr mLeft = NULL;
	mTreePtr mRight = NULL;
} Tree;

/* Function */
void MakeLeftSubTree(mTreePtr mTree, mTreePtr mSub)
{
	if (mTree->mLeft != NULL) { delete mTree->mLeft; }
	mTree->mLeft = mSub;
}
void MakeRightSubTree(mTreePtr mTree, mTreePtr mSub)
{
	if (mTree->mRight != NULL) { delete mTree->mRight; }
	mTree->mRight = mSub;
}
int EvaluateExpTree(mTreePtr mTree)
{
	int op1 = 0, op2 = 0;

	if ((mTree->mLeft == NULL) && (mTree->mRight == NULL)) /* 단말 노드일 경우 */
		return mTree->mData;

	op1 = EvaluateExpTree(mTree->mLeft);
	op2 = EvaluateExpTree(mTree->mRight);

	switch (mTree->mData)
	{
		case ('+') : { return op1 + op2; }
		case ('-') : { return op1 - op2; }
		case ('*') : { return op1 * op2; }
		case ('/') : { return op1 / op2; }
	}

	return 0;
}
void ShowNodeData(mTreePtr mTree)
{
	cout << mTree->mData << endl;
}
void PreOrderTraversal(mTreePtr mTree, mMyFunc mAction)
{
	if (mTree == NULL) return;

	mAction(mTree);
	PreOrderTraversal(mTree->mLeft, mAction);
	PreOrderTraversal(mTree->mRight, mAction);
}
void InOrderTraversal(mTreePtr mTree, mMyFunc mAction)
{
	if (mTree == NULL) return;

	InOrderTraversal(mTree->mLeft, mAction);
	mAction(mTree);
	InOrderTraversal(mTree->mRight, mAction);
}
void PostOrderTraversal(mTreePtr mTree, mMyFunc mAction)
{
	if (mTree == NULL) return;

	PostOrderTraversal(mTree->mLeft, mAction);
	PostOrderTraversal(mTree->mRight, mAction);
	mAction(mTree);
}
mTreePtr MakeExpTree(string mString)
{
	/* Stack */
	stack<mTreePtr> mStack;

	/* Int */
	int mSize = mString.size();

	for (int ii = 0; ii < mSize; ii++)
	{
		/* Node */
		Tree * mTree = new Tree;

		/* 피연산자 */
		if ((mString[ii] >= 65) && (mString[ii] <= 90))
		{ mTree->mData = mString[ii]; }
		/* 연산자 */
		else
		{
			MakeRightSubTree(mTree, mStack.top()); mStack.pop(); /* 스택의 첫번째 값이 오른쪽 노드 값 */ 
			MakeLeftSubTree(mTree, mStack.top()); mStack.pop(); /* 스택의 두번째 값이 왼쪽 노드 값 */
			mTree->mData = mString[ii]; /* 연산자 저장 */
		}

		mStack.push(mTree); /* 만들어진 연산 트리를 저장 */
	}

	return mStack.top(); /* 최종 연산 트리 반환 */
}

int main(void)
{
	string mString;
	cin >> mString;

	/* Tree */
	Tree * mTree = MakeExpTree(mString);

	PostOrderTraversal(mTree, ShowNodeData);

	return 0;
}.
