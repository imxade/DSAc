#include <stdio.h>

#define MAX 100
#define INF 99999

// A utility function to print the solution matrix
void printSolution(int dist[MAX][MAX], int V) {
    printf("The following matrix shows the shortest distances between every pair of vertices\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall(int graph[MAX][MAX], int V) {
    int dist[MAX][MAX], i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, V);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix of the graph (use %d for infinity):\n", INF);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph, V);

    return 0;
}
