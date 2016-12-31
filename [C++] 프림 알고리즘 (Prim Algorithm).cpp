#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 최대 정점의 수 */
#define MAX 10001

/* 그래프 방문 표시 배열 */
bool check[MAX] = { false, };

/* 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍 */
vector<pair<int, int> > mArr[MAX];

void prim()
{
	
	check[1] = true;

	/* 우선 순위 큐 */
	priority_queue<pair<int, int> > q;

	/* 0번 정점을 시작점으로 항상 트리에 가장 먼저 추가 */
	for (pair<int, int> p : mArr[1])
	{ q.push(make_pair(-p.second, p.first)); }
	/* second - 가중치 값 */

	/* MST 최솟값의 합저장 변수 */
	int answer = 0;

	while (!q.empty())
	{
		pair<int, int> p = q.top();
		q.pop();

		/* 끝점이 방문된 점이 있지 않은 경우 */
		if (!check[p.second])
		{
			/* 방문 표시 */
			check[p.second] = true;
			/* 최솟값의 합 덧셈 */
			answer += -p.first;

			int x = p.second;
			for (pair<int, int> p : mArr[x]) /* 연결되는 모든 점의 간선들을 다 넣어준다. */
			{ q.push(make_pair(-p.second, p.first)); }
		}
	}

	cout << answer << endl;
}

int main(void)
{
	int nn = 0, mm = 0;
	cin >> nn >> mm;

	for (int ii = 0; ii < mm; ii++)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;

		mArr[a].push_back(make_pair(b, c));
		mArr[b].push_back(make_pair(a, c));
	}

	prim();

	return 0;
}.
