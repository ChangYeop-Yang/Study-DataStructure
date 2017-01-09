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
int GetHeight(NodePtr bst)
{
	int leftH; /* Left Hight */
	int rightH; /* Right Hight */

				/* 연결 된 노드가 없는 경우 */
	if (bst == NULL) return 0;

	leftH = GetHeight(bst->mLeft); /* 왼쪽 서브트리 높이 계산 */
	rightH = GetHeight(bst->mRight); /* 오른쪽 서브트리 높이 계산 */

									 /* 큰 값의 높이를 반환 */
	return leftH > rightH ? leftH + 1 : rightH + 1;
}
int GetHeightDiff(NodePtr bst)
{
	int lsh; /* left sub tree hight */
	int rsh; /* right sub tree hight */

			 /* 연결 된 노드가 없는 경우 */
	if (bst == NULL) return 0;

	lsh = GetHeight(bst->mLeft); /* 왼쪽 서브트리의 높이 */
	rsh = GetHeight(bst->mRight); /* 오른쪽 서브트리의 높이 */

	return lsh - rsh; /* 균형 인수 계산 결과 반환 (왼쪽 서브트리의 높이 - 오른쪽 서브트리의 높이) */
}
NodePtr RotateLL(NodePtr bst) /* Left-Left Rotate */
{
	/* Node */
	NodePtr pNode = bst; /* Parent Node */
	NodePtr cNode = pNode->mLeft; /* Child Node */

								  /* Left-Left Rotate */
	pNode->mLeft = cNode->mRight;
	cNode->mRight = pNode;

	/* LL Rotate로 인하여 변경 된 루트 노드의 주소 값 반환 */
	return cNode;
}
NodePtr RotateRR(NodePtr bst) /* Right-Right Rotate */
{
	/* Node */
	NodePtr pNode = bst; /* Parent Node */
	NodePtr cNode = pNode->mRight; /* Child Node */

								   /* Right-Right Rotate */
	pNode->mRight = cNode->mLeft;
	cNode->mLeft = pNode;

	/* RR Rotate로 인하여 변경 된 루트 노드의 주소 값 반환 */
	return cNode;
}
NodePtr RotateLR(NodePtr bst) /* Left-Right Rotate */
{
	/* Node */
	NodePtr pNode = bst; /* Parent Node */
	NodePtr cNode = pNode->mLeft; /* Child Node */

								  /* Left-Right Rotate */
	pNode->mLeft = RotateRR(cNode); /* Sub Right-Right Rotate */
	return RotateLL(pNode); /* Left-Left Rotate */
}
NodePtr RotateRL(NodePtr bst) /* Right-Left Rotate */
{
	/* Node */
	NodePtr pNode = bst; /* Parent Node */
	NodePtr cNode = pNode->mRight; /* Child Node */

								   /* Right-Left Rotate */
	pNode->mRight = RotateLL(cNode); /* Sub Left-Left Rotate */
	return RotateRR(pNode); /* Right-Right Rotate */
}
NodePtr Rebalance(NodePtr * pRoot)
{
	/* Integer */
	int hDiff = GetHeightDiff(*pRoot); /* 균형 인수 계산 */

									   /* 균형 인수가 +2 이상이면 LL 상태 또는 LR 상태이다. */
	if (hDiff > 1)
	{
		*pRoot = GetHeightDiff((*pRoot)->mLeft) > 0 ? RotateLL(*pRoot) : RotateLR(*pRoot);
	}

	/* 균형 인수가 -2 이하이면 RR 상태 또는 RL 상태이다. */
	if (hDiff < -1)
	{
		*pRoot = GetHeightDiff((*pRoot)->mRight) < 0 ? RotateRR(*pRoot) : RotateRL(*pRoot);
	}

	return *pRoot;
}
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
NodePtr BSTInsert(NodePtr * mRoot, int data)
{
	if (*mRoot == NULL) { (*mRoot) = new Node(); (*mRoot)->mData = data; } /* Root Node인 경우 */
	else if (data < (*mRoot)->mData) { BSTInsert(&((*mRoot)->mLeft), data); *mRoot = Rebalance(mRoot); }
	else if (data > (*mRoot)->mData) { BSTInsert(&((*mRoot)->mRight), data); *mRoot = Rebalance(mRoot); }
	else { return NULL; } /* 중복 Key 값이 저장되는 경우 */

	return (*mRoot);
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
	{
		pNode->mLeft == dNode ? RemoveLeftSubTree(pNode) : RemoveRightSubTree(pNode);
	}
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

	/* Rebalance */
	(*pRoot) = Rebalance(pRoot);

	return dNode;
}

int main(void)
{
	Node * avl = new Node;
	
	BSTInsert(&avl, 1);
	BSTInsert(&avl, 2);
	BSTInsert(&avl, 3);
	BSTInsert(&avl, 4);
	BSTInsert(&avl, 5);
	BSTInsert(&avl, 6);
	BSTInsert(&avl, 7);
	BSTInsert(&avl, 8);
	BSTInsert(&avl, 9);

	cout << ":::: Root Node ->::::" << avl->mData << endl;
	cout << ":::: L Node ->::::" << avl->mLeft->mData << endl;
	cout << ":::: R Node ->::::" << avl->mRight->mData << endl;


	return 0;
}
