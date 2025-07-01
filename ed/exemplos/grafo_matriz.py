#Representação por matriz
class Graph:
    def __init__(self):
        self.vertices = []
        self.adj_matrix = []

    def addVertex(self, key):
        if key not in self.vertices:
            self.vertices.append(key)

            for row in self.adj_matrix:
                row.append(0)

            new_row = [0] * len(self.vertices)
            self.adj_matrix.append(new_row)

    def addEdge(self, fromVert, toVert, weight=0):
        if fromVert in self.vertices and toVert in self.vertices:
            linha = self.vertices.index(fromVert)
            coluna = self.vertices.index(toVert)
            self.adj_matrix[linha][coluna] = weight

    def getVertex(self, vertKey):
        return vertKey if vertKey in self.vertKey else None

    def getVertices(self):
        return self.vertices

    def __contains__(self, vertKey):
        return vertKey in self.vertices

