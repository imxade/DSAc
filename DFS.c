#include <stdio.h>

#define MAX 100

void dfs(int graph[MAX][MAX], int n, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, n, i, visited);
        }
    }
}

int main() {
    int n, e, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    int graph[MAX][MAX] = {0};
    printf("Enter edges (u v) format:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // for undirected graph
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    dfs(graph, n, start, visited);
    printf("\n");
    return 0;
}
/ 