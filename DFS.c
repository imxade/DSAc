#include <stdio.h>

#define MAX 100

void dfs(int graph[][MAX], int n, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(graph, n, i, visited);
        }
    }
}

int main() {
    int n, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    dfs(graph, n, start, visited);
    printf("\n");
    return 0;
}
