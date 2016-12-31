#include <iostream>
using namespace std;

/* Typedef */
typedef struct node * NodePtr;

/* Struct */
typedef struct node
{
	int mData;
	NodePtr mLeft = NULL;
	NodePtr mRight = NULL;
} Node;

/* Function */
void MakeLeftSubTree(NodePtr mRoot, NodePtr mSub)
{
	if (mRoot->mLeft != NULL) { delete (mRoot->mLeft); }
	mRoot->mLeft = mSub;
}
void MakeRightSubTree(NodePtr mRoot, NodePtr mSub)
{
	if (mRoot->mRight != NULL) { delete (mRoot->mRight); }
	mRoot->mRight = mSub;
}
void BSTInsert(NodePtr * mRoot, int data)
{
	/* Node */
	NodePtr pNode = NULL; /* Parent Node */
	NodePtr cNode = * mRoot; /* Current Node */
	
	/* 새로운 노드가 (새 데이터가 담긴 노드) 추가될 위치를 찾는다. */
	while (cNode != NULL)
	{
		if (data == cNode->mData) { return; } /* Key의 중복을 허용하지 않는다. */

		pNode = cNode;

		if (cNode->mData > data) { cNode = cNode->mLeft; } /* 현재 노드보다 새로운 값이 작은 경우는 왼쪽 위치 반환 */
		else { cNode = cNode->mRight; } /* 현재 노드보다 새로운 값이 큰 경우는 오른쪽 위치 반환 */ 
	}

	/* Node */
	NodePtr nNode = new Node; /* New Node */
	nNode->mData = data;

	/* Parent Node의 자식 노드로 새 노드를 추가 */
	if (pNode != NULL)
	{
		if (nNode->mData < pNode->mData) { MakeLeftSubTree(pNode, nNode); } /* 부모 노드보다 새로운 노드 값이 작은 경우는 왼쪽 연결 */
		else { MakeRightSubTree(pNode, nNode); } /* 부모 노드보다 새로운 노드 값이 큰 경우는 오른쪽 연결 */
	}
	/* 새 노드가 루트 노드인 경우 */
	else { *mRoot = nNode; }
}
NodePtr BSTSearch(NodePtr mFind, int target)
{
	/* Node */
	NodePtr cNode = mFind; /* Current Node */

	while (cNode != NULL)
	{
		if (target == cNode->mData) { return cNode; } /* 찾고자 하는 값은 찾은 경우 Node 반환 */
		else if (target < cNode->mData) { cNode = cNode->mLeft; } /* 찾고자 하는 값보다 큰 경우 현재 노드의 왼쪽 주소 반환 */
		else { cNode = cNode->mRight; } /* 찾고자 하는 값보다 작은 경우 현재 노드의 오른쪽 주소 반환 */
	}

	return NULL; /* 탐색대상이 저장되어 있지 않은 경우 */
}
NodePtr RemoveLeftSubTree(NodePtr mNode)
{
	/* Node */
	NodePtr delNode = NULL;

	if (mNode != NULL)
	{
		delNode = mNode->mLeft;
		mNode->mLeft = NULL;
	} return delNode;
}
NodePtr RemoveRightSubTree(NodePtr mNode)
{
	/* Node */
	NodePtr delNode = NULL;

	if (mNode != NULL)
	{
		delNode = mNode->mRight;
		mNode->mRight = NULL;
	} return delNode;
}
NodePtr BSTDelete(NodePtr * pRoot, int target)
{
	/* Node */
	NodePtr pVRoot = new Node; /* 가상 루트 노드 */
	NodePtr pNode = pVRoot; /* Parent Node */
	NodePtr cNode = *pRoot; /* Current Node */
	NodePtr dNode = NULL; /* Delete Node */

	/* Root Node를 가상 루트 로드가 가리키는 노드의 오른쪽 자식 노드가 되게 한다. */
	pVRoot->mRight = *pRoot;

	/* 삭제 대상인 노드를 탐색 */
	while (cNode != NULL && cNode->mData != target)
	{
		pNode = cNode;

		if (target < cNode->mData) { cNode = cNode->mLeft; }
		else { cNode = cNode->mRight; }
	}

	/* 삭제할 대상이 존재하지 않는 경우 */
	if (cNode == NULL) { return NULL; }

	dNode = cNode; /* 삭제 대상을 dNode가 가리키게 한다. */

	/* 첫번째 경우 : 삭제 대상이 단말 노드인 경우 */
	if (dNode->mLeft == NULL && dNode->mRight == NULL)
	{ pNode->mLeft == dNode ? RemoveLeftSubTree(pNode) : RemoveRightSubTree(pNode); }
	/* 두번째 경우 : 삭제 대상이 하나의 자식 노드를 갖는 경우 */
	else if (dNode->mLeft == NULL || dNode->mRight == NULL)
	{
		/* Node */
		NodePtr dcNode = (dNode->mLeft != NULL ? dNode->mLeft : dNode->mRight); /* 삭제 대상의 자식노드를 가리킨다. */

	 	pNode->mLeft == dNode ? pNode->mLeft = dcNode : pNode->mRight = dcNode;
	}
	/* 세번째 경우 : 두 개의 자식 노드를 모두 갖는 경우 */
	else
	{
		/* Node */
		NodePtr mpNode = dNode; /* 대체 노드의 부모 노드를 가리킨다. */
		NodePtr mNode = dNode->mRight; /* 대체 노드를 가리킨다. */

		/* Integer */
		int mDel = 0;

		/* 삭제 대상의 대체 노드를 찾는다. */
		while (mNode->mLeft != NULL)
		{
			mpNode = mNode;
			mNode = mNode->mLeft;
		}

		/* 대체 노드에 저장 된 값을 삭제할 노드에 대입 */
		mDel = dNode->mData;
		dNode->mData = mNode->mData;

		/* 대체 노드의 부모 노드와 자식 노드를 연결한다. */
		mpNode->mLeft == mNode ? (mpNode->mLeft = mNode->mRight) : (mpNode->mRight = mNode->mRight);
		
		dNode = mNode;
		dNode->mData = mDel;
	}

	/* 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리 */
	if (pVRoot->mRight != *pRoot) { *pRoot = pVRoot->mRight; } /* 루트 노드의 변경을 반영 */

	delete(pVRoot);
	return dNode;
}

int main(void)
{
	/* Node */
	Node * mRoot = NULL;
	Node * mFind = NULL;

	int mNum1 = 0, mNum2 = 0;
	cin >> mNum1;

	for (int ii = 0, mInput = 0; ii < mNum1; ii++)
	{
		cin >> mInput;
		BSTInsert(&mRoot, mInput);
	}

	mFind = BSTSearch(mRoot, 30);
	cout << mFind->mData << endl;

	mFind = BSTDelete(&mRoot, 30);
	cout << (mFind ? "삭제" : "안삭제") << endl;

	return 0;
}
