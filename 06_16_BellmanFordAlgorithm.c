#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int src, dest, weight;
} Edge;

void bellmanFord(int V, int E, Edge edges[], int src)
{
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int j = 0; j < E; j++)
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int V = 5;
    int E = 8;

    Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    bellmanFord(V, E, edges, 0);

    return 0;
}
