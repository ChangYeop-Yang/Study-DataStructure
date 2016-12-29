#include <iostream>
#include <cstdlib>
using namespace std;

/* Typedef */
typedef struct tree * mTreePtr;
typedef void mMyFunc (mTreePtr mData);

/* Struct */
typedef struct tree
{
	int mData;
	mTreePtr mLeft = NULL;
	mTreePtr mRight = NULL;
} Tree;

/* Function */
mTreePtr MakeTree(int mData)
{
	/* Tree */
	Tree * mNewTree = new Tree;
	mNewTree->mData = mData;

	return mNewTree;
}
void MakeSubTree(mTreePtr mTree, int mData)
{
	if (mTree->mData > mData)
	{ mTree->mLeft == NULL ? mTree->mLeft = MakeTree(mData) : MakeSubTree(mTree->mLeft, mData); }
	else
	{ mTree->mRight == NULL ? mTree->mRight = MakeTree(mData) : MakeSubTree(mTree->mRight, mData); }
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

void DeleteTree(mTreePtr mTree) { delete(mTree); }
void PrintTree(mTreePtr mTree) { cout << mTree->mData << endl; }

int main(void)
{
	/* Root Node Create */
	Tree * mRoot = NULL;
	
	for (int ii = 0; ii < 10; ii++)
	{
		int mIntager = 0;
		cin >> mIntager;

		if (mRoot == NULL) { mRoot = new Tree; mRoot->mData = mIntager; }
		else { MakeSubTree(mRoot, mIntager); }
	}

	PostOrderTraversal(mRoot, PrintTree);

	return 0;
}
