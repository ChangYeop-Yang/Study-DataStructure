#include <stdio.h>
#include <string.h>
#define SIZE 1001
 
/* Integer Array */
int Array[SIZE][SIZE];
int Visit[SIZE];
 
int main(void)
{
    /* Integer */
    int N = 0, M = 0, V = 0;
    /*
    * N - 정점의 개수
    * M - 간선의 개수
    * V - 정점의 번호
    */
    int V1 = 0, V2 = 0;
    
    /* 입력 */
    scanf("%d %d %d", &N, &M, &V);
    for (int count = 0; count < M; count++)
    {
        scanf("%d %d", &V1, &V2);
        /* 정점을 간선으로 연결하는 부분 */
        Array[V1][V2] = Array[V2][V1] = 1;
    }
 
    /* Breadth First Search */
    BFS(V, N); printf("\n");
 
    return 0;
}
/* Breadth First Search */
int BFS(int index, int N)
{
    /* Integet */
    unsigned int REAR = 0;
    unsigned int FRONT = 0;
    unsigned int Queue[1001];
 
    /* 방문 표시 */
    Visit[index] = 1;
 
    /* Queue */
    Queue[REAR] = index;
    REAR = (REAR + 1) % SIZE;
 
    while (REAR != FRONT)
    {
        /* Index 위치 변경 */
        index = Queue[FRONT];
        FRONT = (FRONT + 1) % SIZE;
        printf("%d ", index);
 
        for (int count = 0; count <= N; count++)
        {
            if (Visit[count] == 0 && Array[index][count] == 1)
            {
                /* 방문 표시 */
                Visit[count] = 1;
                /* Queue */
                Queue[REAR] = count;
                REAR = (REAR + 1) % SIZE;
            }
        }
    }
}.
