#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2)
{
    int *edge1 = (int *)p1;
    int *edge2 = (int *)p2;
    return edge1[2] - edge2[2];
}

void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]); 
}

void unionSet(int u, int v, int parent[], int rank[], int n)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) 
    {
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int kruskalAlgo(int n, int edge[][3])
{
    qsort(edge, n, sizeof(edge[0]), comparator); 

    int parent[n];
    int rank[n];

    makeSet(parent, rank, n);

    int minCost = 0;
    for (int i = 0; i < n; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        if (findParent(parent, u) != findParent(parent, v))
        {
            unionSet(u, v, parent, rank, n);
            minCost += wt;
        }
    }

    return minCost;
}

int main()
{
    int edge[5][3] = {{0, 1, 9},
                      {0, 2, 6},
                      {0, 3, 2},
                      {1, 3, 6},
                      {2, 3, 4}};
    
    printf("Minimum cost of MST: %d\n", kruskalAlgo(5, edge));

    return 0;
}
