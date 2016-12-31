#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define INF 999999999

/* Struct */
typedef struct rmq /* 배열의 구간 최소 쿼리를 해결하기 위한 구간 트리 */
{
	int n; /* 배열의 길이 */
	vector<int> rangeMin; /* 각 구간의 최소치 */

	rmq(const vector<int> & array)
	{
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	/* Node가 array[left..right] 배열을 표현할 때 Node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환한다. */
	int init(const vector<int> & array, int left, int right, int node)
	{
		/* 터미널 노드일 경우 */
		if (left == right) { return rangeMin[node] = array[left]; }

		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	/* Node가 표현하는 범위 array[nodeLeft..nodeRight]가 주어질 때 이 범위와 array[left..right]의 교집합의 최소치를 구한다. */
	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		/* 두 구간이 겹치지 않으면 아주 큰 값을 반환한다. : 무시되는 경우 */
		if (right < nodeLeft || nodeRight < left) { return INF; }
		/* Node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우 */
		if (left <= nodeLeft && nodeRight <= right) { return rangeMin[node]; }
		/* 양쪽 구간을 나눠서 푼 뒤 결과를 합친다. */
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right) { return query(left, right, 1, 0, n - 1); }
} RMQ;

vector<int> mVector;

int main(void)
{
	int mNum1 = 0, mNum2 = 0;
	scanf("%d %d", &mNum1, &mNum2);

	for (int ii = 0, mTemp; ii < mNum1; ii++)
	{
		scanf("%d", &mTemp); mVector.push_back(mTemp);
	}

	RMQ mRMQ(mVector);

	for (int ii = 0; ii < mNum2; ii++)
	{
		int mTemp[2] = { 0,0 };
		scanf("%d %d", &mTemp[0], &mTemp[1]);

		printf("%d\n", mRMQ.query(mTemp[0] - 1, mTemp[1] - 1));
	}

	return 0;
}
