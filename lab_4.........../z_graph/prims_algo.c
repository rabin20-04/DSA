#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define INF 9999

int findMinKey(int key[], bool mstSet[], int n)
{
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int n)
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[MAX][MAX], int n)
{
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        int u = findMinKey(key, mstSet, n);

        mstSet[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}};

    printf("Minimum Spanning Tree:\n");
    primMST(graph, n);

    return 0;
}