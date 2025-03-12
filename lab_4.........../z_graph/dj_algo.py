import math

G = {
    "A": {"B": 3, "C": 1},
    "B": {"A": 3, "C": 7, "D": 5, "E": 1},
    "C": {"A": 1, "B": 7, "D": 2},
    "D": {"C": 2, "B": 5, "E": 7},
    "E": {"D": 7, "B": 1},
}


def reconstruct_path(previous, vertex):
    path = vertex
    while previous[vertex] != " ":
        path = previous[vertex] + "->" + path
        vertex = previous[vertex]
    return path


# print [A][B] gives value 3
def initialize(G, start):
    cost = dict()
    previous = dict()
    for vertex in G:
        cost[vertex] = math.inf
        # set initial cost of all to infinte then later on to zero to self and infinite to others
        previous[vertex] = " "
    cost[start] = 0
    return cost, previous


def relax(G, u, v, cost, previous):
    if cost[v] > cost[u] + G[u][v]:
        cost[v] = cost[u] + G[u][v]
        previous[v] = u
    return cost, previous


def compute_least_cost_vertex(cost, visited):  # cost is the dict
    leastCost = math.inf
    leastCostVertex = " "
    for vertex in cost:
        if vertex not in visited:
            if cost[vertex] < leastCost:
                leastCost = cost[vertex]
                leastCostVertex = vertex
    return leastCostVertex


def compute_shortest_path(G, start):
    cost, previous = initialize(G, start)
    visited = []
    while len(visited) < len(G):
        currentVertex = compute_least_cost_vertex(cost, visited)
        visited.append(currentVertex)
        for adjacentElements in G[currentVertex]:
            if adjacentElements not in visited:
                cost, previous = relax(
                    G, currentVertex, adjacentElements, cost, previous
                )
    return cost, previous


start = "A"
cost, previous = compute_shortest_path(G, start)
print(cost)
print(previous)


for vertex in G:
    print(
        f"Shortest path from {start} to {vertex} is {reconstruct_path(previous,vertex)}"
    )
    print(f"cost of path is {cost[vertex]}")



# it cannot handel edges with negative weights


# lab task
# implement kruskals and prims algorithm for computing minimum spanning tree in python 
