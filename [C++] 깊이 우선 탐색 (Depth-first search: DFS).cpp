#include <stdio.h>
#include <string.h>
 
int _Visit[101] = { 0, };
int _Array[101][101] = { 0, };
 
int N = 0, G = 0, S = 0;
 
void DFS(int index);
 
int main()
{
 
    int itr = 0;
    int nCount = 0;        /* 문제의 테스트 케이스 */
    int _Count = 0;
    int V1 = 0, V2 = 0;
 
    scanf("%d", &nCount);    /* 테스트 케이스 입력 */
 
    for (itr = 0; itr<nCount; itr++)
    {
        printf("#testcase%d\n", itr + 1);
        
        /* 배열 초기화 */
        memset(_Visit, 0, sizeof(_Visit));
        memset(_Array, 0, sizeof(_Array));
 
        /* 변수 초기화 */
        N = G = S = 0;
 
        scanf("%d %d %d", &N, &S, &G); /* 입력 */
        for (_Count = 0; _Count < G; _Count++)
        { 
            scanf("%d %d", &V1, &V2); /* 입력 */
            _Array[V1][V2] = _Array[V2][V1] = 1;
        }
 
        DFS(S); /* DFS */
        printf("\n");
    }
    return 0;    /* 반드시 return 0으로 해주셔야합니다. */
}
 
void DFS(int index)
{
    int _Count = 0;
 
    _Visit[index] = 1; /* 방문 표시 */
    printf("%d ", index);
    
    for (_Count = 1; _Count <= N; _Count++)
    {
        /* 방문을 하지 않은 위치 */
        if (_Visit[_Count] == 0 && _Array[index][_Count] == 1)
        { DFS(_Count); }
    }
}
