#include <iostream>
#include <cstdio>
using namespace std;

#define INF 99999999
#define MAX_V 501

/* Struct */
typedef struct edge
{
	int source; /* From */
	int dest; /* To */
	int weight; /* 가중치 */
} Edge;

/* Intager Array */
int mDistance[MAX_V];

/* Struct Array */
Edge mEdgeArray[6001];

bool Bellman(int source, int mVertax, int mEdge)
{
	/* Distance 초기화 */
	for (int ii = 0; ii < mVertax; ii++)
	{ mDistance[ii] = INF; }

	mDistance[source] = 0;

	for (int ii = 0; ii < mVertax - 1; ii++) /* 모든 정점 순회 */
	{
		for (int jj = 0; jj < mEdge; jj++) /* 모든 간선 순회 */
		{
			/* 최단 경로의 거리 값 갱신 */
			if (mDistance[mEdgeArray[jj].dest] > (mDistance[mEdgeArray[jj].source] + mEdgeArray[jj].weight) )
			{ mDistance[mEdgeArray[jj].dest] = mDistance[mEdgeArray[jj].source] + mEdgeArray[jj].weight; } 
		}
	}

	for (int ii = 0; ii < mEdge; ii++)
	{
		/* 음의 순환 사이클이 발견 된 경우 */
		if (mDistance[mEdgeArray[ii].dest] > (mDistance[mEdgeArray[ii].source] + mEdgeArray[ii].weight))
		{ cout << -1 << endl; return false; }
	}

	for (int ii = 1; ii < mVertax; ii++)
	{ printf("%d\n", (mDistance[ii] != INF ? mDistance[ii] : -1)); }
}

int main(void)
{
	int mVertax = 0, mEdge = 0;
	scanf("%d %d", &mVertax, &mEdge);

	for (int ii = 0; ii < mEdge; ii++)
	{ 
		int A = 0, B = 0, C = 0;
		scanf("%d %d %d", &A, &B, &C);

		mEdgeArray[ii].source = A - 1;
		mEdgeArray[ii].dest = B - 1;
		mEdgeArray[ii].weight = C;
	}

	Bellman(0, mVertax, mEdge);

	return 0;
}
