G = {
    "A": ["M", "Q"],
    "M": ["A", "Z", "C"],
    "Q": ["A", "Y", "R"],
    "Z": ["M"],
    "C": ["M"],
    "Y": ["Q"],
    "R": ["Q"],
}


def DFT(G, start):
    stack = []
    visited = []
    stack.append(start)
    while stack:
        poppedVertex = stack.pop()
        visited.append(poppedVertex)
        for adjacent_elements in G[poppedVertex]:
            if adjacent_elements not in visited and adjacent_elements not in stack:
                stack.append(adjacent_elements)
    return visited


start = "A"
print(DFT(G, start))


# ['A', 'Q', 'R', 'Y', 'M', 'C', 'Z']
