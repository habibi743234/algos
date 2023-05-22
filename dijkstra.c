#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void dijakstra(int **graph, int numVertices, int source)
{
    int distance[numVertices], visited[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[source] = 0;

    for (int i = 0; i < numVertices - 1; i++)
    {
        int minDistance = INT_MAX, minVertex;
        for (int j = 0; j < numVertices; j++)
        {
            if (!visited[j] && distance[j] < minDistance)
            {
                minDistance = distance[j];
                minVertex = j;
            }
        }
        visited[minVertex] = true;

        for (int v = 0; v < numVertices; v++)
        {
            if (!visited[v] && graph[minVertex][v] && distance[minVertex] != INT_MAX &&
                distance[minVertex] + graph[minVertex][v] < distance[v])
                distance[v] = distance[minVertex] + graph[minVertex][v];
        }
    }
    printf("Vertex\tDistance\n");
    for (int v = 0; v < numVertices; v++)
        printf("%d\t%d\t\t\n", v, distance[v]);
}

int main()
{
    int numVertices, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int **graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
        graph[i] = (int *)malloc(numVertices * sizeof(int));

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijakstra(graph, numVertices, source);

    return 0;
}

// 3
/*
031
301
110
*/
