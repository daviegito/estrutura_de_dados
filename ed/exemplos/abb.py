#Melhor caso: O(log n); Pior caso: O(n)
class TreeNode:

    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None

    def insert(self, key, value):
        if key < self.key:
            if self.left:
                self.left.insert(key, value)
            else:
                self.left = TreeNode(key, value)

        elif key > self.key:
            if self.right:
                self.right.insert(key, value)
            else:
                self.right = TreeNode(key, value)

    def __setitem__(self, key, value):
        self.insert(key, value)

    def delete(self, key):
        if key < self.key and self.left:
            self.left = self.left.delete(key)
        elif key > self.key and self.right:
            self.right = self.right.delete(key)
        else:
            #o nó a ser excluído não tem filhos
            if not self.left and not self.right:
                return None
            #O nó a ser excluído tem apenas um filho
            if not self.left:
                return self.right
            if not self.right:
                return self.left
            #O nó excluído tem 2 filhos
            min_larger_node = self.right.find_min()
            self.key, self.value = min_larger_node.ley, min_larger_node.value
            self.right = self.right.delete(min_larger_node.key)
        return self

    def find_min(self):
        current = self
        while current.left:
            current = current.left
        return current

    def search(self, key):
        if key == self.key:
            return self.value
        elif key < self.key and self.left:
            return self.left.search(key)
        elif key > self.key and self.right:
            return self.right.search(key)
        return None

    def __getitem__(self, key):
    #Permite usar a sintaxe de colchetes para acessar valores
        return self.search(key)

    def __contains__(self, key):
    #Permite usar o operador in 12 in bst
        return self.search(key) is not None

    def height(node):
        if node is None:
            return -1
        left_height = height(node.left)
        right_height = height(node.right)
        return max(left_height, right_height) + 1

    def is_balanced(node):
        if node is None:
            return True

        left_height = calculate_height(node.left)
        right_height = calculate_height(node.right)

        if abs(left_height - right_height) > 1:
            return False

        return is_balanced(node.left) and is_balanced(node.right)

    def build_tree(lista):
        if not lista:
            return None

        mid = len(lista) // 2
        root = TreeNode(lista[mid], lista[mid])
        root.left = build_tree(lista[:mid])
        root.right = build_tree(lista[mid + 1:])
        return root



