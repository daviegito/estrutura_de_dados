#Representação de árvores usando objetos
class BinaryTree:
    def __init__(self, rootObj):
        self.key = rootObj
        self.leftChild = None
        self.rightChild = None

    def getRootVal(self):
        return self.key

    def getLeftChild(self):
        return self.leftChild

    def getRightChild(self):
        return self.rightChild

    def preorder(self):
        print(self.getRootVal())  # processa o nodo
        if self.getLeftChild():
            self.getLeftChild().preorder()
        if self.getRightChild():
            self.getRightChild().preorder()

    def inorder(self):
        if self.getLeftChild():
            self.getLeftChild().inorder()
        print(self.getRootVal())
        if self.getRightChild():
            self.getRightChild().inorder()

    def postorder(self):
        if self.getLeftChild():
            self.getLeftChild().postorder()
        if self.getRightChild():
            self.getRightChild().postorder()
        print(self.getRootVal())

arvore = BinaryTree("B")
c = BinaryTree("C")
a = BinaryTree("A")
l = BinaryTree("L")
e = BinaryTree("E")

c.leftChild = a
c.rightChild = l
l.rightChild = e

o = BinaryTree("O")
m = BinaryTree("M")

o.leftChild = m
arvore.rightChild = o
arvore.leftChild = c

print("Pré-ordem:")
arvore.preorder()

print("\nEm ordem:")
arvore.inorder()

print("\nPós-ordem:")
arvore.postorder()






