#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

struct Edge {
    int source, destination, weight;
};

void bellmanFord(int graph[MAX_NODES][MAX_NODES], int V, int E, int source) {
    int distance[MAX_NODES];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;
    distance[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative-weight cycle.\n");
            return;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, distance[i]);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the edges in the format (source, destination, weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(graph, V, E, source);

    return 0;
}
