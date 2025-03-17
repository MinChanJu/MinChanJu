#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000 // 매우 큰 값(간선 없음 표시용)

// MST 간선을 저장할 구조체
typedef struct {
    int u, v;
    int cost;
} MSTEdge;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m); // n: 정점 수, m: 간선 수

    // 인접행렬 동적 할당
    int **cost = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        cost[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i == j) cost[i][j] = 0; // 자기 자신으로의 비용은 0
            else cost[i][j] = INF;      // 초기에는 간선 없음
        }
    }

    // 간선 입력 받기
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        // 무방향 그래프 가정
        cost[u][v] = c;
        cost[v][u] = c;
    }

    // MST 집합 관리 배열
    int *included = (int *)calloc(n, sizeof(int));
    included[0] = 1; // 시작점: 0번 정점

    MSTEdge *mstEdges = (MSTEdge *)malloc((n - 1) * sizeof(MSTEdge));
    int edgeCount = 0;

    // 프림 알고리즘
    while (edgeCount < n - 1) {
        int minCost = INF;
        int selectedU = -1, selectedV = -1;

        // MST 집합에 포함된 정점과 포함되지 않은 정점 사이의 최소 비용 간선 찾기
        for (int u = 0; u < n; u++) {
            if (included[u]) {
                for (int v = 0; v < n; v++) {
                    if (!included[v] && cost[u][v] < minCost) {
                        minCost = cost[u][v];
                        selectedU = u;
                        selectedV = v;
                    }
                }
            }
        }

        if (selectedV == -1) {
            // 선택할 간선이 없음 -> MST 완성 불가
            break;
        }

        // 최소 간선 선택
        included[selectedV] = 1;
        mstEdges[edgeCount].u = selectedU;
        mstEdges[edgeCount].v = selectedV;
        mstEdges[edgeCount].cost = minCost;
        edgeCount++;
    }

    printf("=======\n");

    // MST가 완성되지 않은 경우
    if (edgeCount < n - 1) {
        printf("no spanning tree\n");
    } else {
        // MST 간선 출력 (u v cost)
        for (int i = 0; i < edgeCount; i++) {
            printf("%c %c %d\n", mstEdges[i].u+65, mstEdges[i].v+65, mstEdges[i].cost);
        }
    }

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        free(cost[i]);
    }
    free(cost);
    free(included);
    free(mstEdges);

    return 0;
}