#include <iostream>
#include <algorithm>
#define SIZE 100010
using namespace std;
 
/* Struct */
typedef struct edge * ePtr;
typedef struct edge
{
    int N; /* 시작점 */
    int M; /* 도착점 */
    int W; /* 가중치 */
} Edge;
 
/* Edge */
Edge mEdge[SIZE];
 
/* Integer */
int MAX[SIZE];
 
/* Kruskal Algorithm */
long long int Kruskal(int N, int M)
{
    /* Integer */
    long long int mSum = 0; /* 가중치의 합을 저장하는 변수 */
 
    /* 정점의 수 만큼 배열 초기화 */
    for (int ii = 1; ii <= N; ii++) { MAX[ii] = ii; }
    for (int jj = 0; jj < M; jj++)
    {
        int mStart = MAX[mEdge[jj].N];
        while (mStart != MAX[mStart]) { mStart = MAX[mStart]; }
 
        int mEnd = MAX[mEdge[jj].M];
        while (mEnd != MAX[mEnd]) { mEnd = MAX[mEnd]; }
 
        if (mStart != mEnd)
        {
            mStart < mEnd ? MAX[mEnd] = mStart : MAX[mStart] = mEnd;
            
            /* 가중차 합 저장 */
            mSum += mEdge[jj].W;
        }
    }
 
    return mSum;
}
 
/* Compare */
int Compare(const void * v1, const void * v2)
{ return ((ePtr)v1)->W > ((ePtr)v2)->W ? 1 : 0; }
 
int main(void)
{
    /* Integer */
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;
 
    /* Input */
    for (int count = 0; count < num2; count++)
    {
        cin >> mEdge[count].N >> mEdge[count].M >> mEdge[count].W;
    }
 
    /* Qsort */
    qsort((void *)mEdge, num2, sizeof(mEdge[0]), Compare);
 
    /* output */
    cout << Kruskal(num1, num2) << endl;
 
    return 0;
}
