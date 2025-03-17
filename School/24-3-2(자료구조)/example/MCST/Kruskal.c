#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v, w;
    int cost;
} Edge;

int *parent, *rankArr;

// 경로 압축을 활용한 Find 함수
int findSet(int x) {
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

// 랭크를 이용한 Union 함수
int unionSet(int x, int y) {
    int rx = findSet(x);
    int ry = findSet(y);
    if (rx == ry) return 0; // 이미 같은 집합이면 유니온 불필요

    if (rankArr[rx] < rankArr[ry]) {
        parent[rx] = ry;
    } else if (rankArr[rx] > rankArr[ry]) {
        parent[ry] = rx;
    } else {
        parent[ry] = rx;
        rankArr[rx]++;
    }
    return 1;
}

// qsort를 위한 비교 함수(간선을 가중치 오름차순으로 정렬)
int compareEdges(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->cost - e2->cost;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m); // 정점 수, 간선 수 입력

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].v, &edges[i].w, &edges[i].cost);
    }

    // 간선들을 비용 기준 오름차순 정렬
    qsort(edges, m, sizeof(Edge), compareEdges);

    // 유니온 파인드 초기화
    parent = (int *)malloc(n * sizeof(int));
    rankArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    int edgeCount = 0; // MST에 추가된 간선 수
    int i = 0;         // edges 배열을 순회할 인덱스

    // MST를 이루는 간선을 저장할 배열
    Edge *mstEdges = (Edge *)malloc((n - 1) * sizeof(Edge));

    // 크루스칼 알고리즘
    while (edgeCount < n - 1 && i < m) {
        int v = edges[i].v;
        int w = edges[i].w;
        int cost = edges[i].cost;
        i++;

        // 사이클 검사
        if (findSet(v) != findSet(w)) {
            unionSet(v, w);
            // MST 간선 목록에 추가
            mstEdges[edgeCount].v = v;
            mstEdges[edgeCount].w = w;
            mstEdges[edgeCount].cost = cost;
            edgeCount++;
        } else {
            // 사이클 형성 -> 해당 간선은 버림
        }
    }

    printf("========\n");

    // 스패닝 트리 완성 불가 시
    if (edgeCount < n - 1) {
        printf("no spanning tree\n");
    } else {
        // MST 출력
        // MST는 edgeCount == n-1 이므로
        for (int j = 0; j < edgeCount; j++) {
            printf("%c %c %d\n", mstEdges[j].v+65, mstEdges[j].w+65, mstEdges[j].cost);
        }
    }

    free(edges);
    free(mstEdges);
    free(parent);
    free(rankArr);

    return 0;
}