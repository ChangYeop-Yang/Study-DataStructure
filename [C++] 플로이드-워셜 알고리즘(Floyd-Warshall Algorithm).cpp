#define MAX_V 101
#define INF 99999999

int mCost[MAX_V][MAX_V]; /* 정점에서 갈 수 있는 경로 간에 최소값을 저장하는 배열 */
int mArr[MAX_V][MAX_V]; /* 경로 테이블 */

void doFloyd(int mVertax)
{
	/* Init */
	for (int ii = 1; ii <= mVertax; ii++)
	{
		for (int jj = 1; jj <= mVertax; jj++)
		{ mCost[ii][jj] = mArr[ii][jj]; } /* 인접 행렬 값을 통해서 최단 경로를 초기화한다. */
	}

	/* kk = 경유점, ii = 출발점, jj = 도착점 */
	for (int kk = 1; kk <= mVertax; kk++) /* 경유점 */
	{
		for (int ii = 1; ii <= mVertax; ii++) /* 출발점 */
		{
			for (int jj = 1; jj <= mVertax; jj++) /* 도착점 */
			{
				if (mCost[ii][jj] > (mCost[ii][kk] + mCost[kk][jj]) )
				{
					mCost[ii][jj] = mCost[ii][kk] + mCost[kk][jj];
				}
			}
		}
	}

	for (int ii = 1; ii <= mVertax; ii++)
	{
		for (int jj = 1; jj <= mVertax; jj++)
		{
			cout << (mCost[ii][jj] == INF ? 0 : mCost[ii][jj]) << " ";
		} cout << endl;
	}
}
