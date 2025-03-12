G = {
    "A": ["M", "Q"],
    "M": ["A", "Z", "C"],
    "Q": ["A", "Y", "R"],
    "Z": ["M"],
    "C": ["M"],
    "Y": ["Q"],
    "R": ["Q"],
}


def BFT(G, start):
    stack = []
    visited = []
    stack.append(start)
    while stack:
        poppedVertex = stack.pop(0)  # index 0
        visited.append(poppedVertex)
        for adjacent_elements in G[poppedVertex]:
            if adjacent_elements not in visited and adjacent_elements not in stack:
                stack.append(adjacent_elements)
    return visited


start = "A"
print(BFT(G, start))


# ['A', 'M', 'Q', 'Z', 'C', 'Y', 'R']
