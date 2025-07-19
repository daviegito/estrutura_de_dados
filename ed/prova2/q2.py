#Melhor caso: O(log n); Pior caso: O(n)
class ArvoreBinaria():

    def __init__(self, dado, esq=None, dir=None):
        self.dado = dado
        self.esq = esq
        self.dir = dir

def verificaSimetria(raiz):
    if raiz is None:
        return True

    def nos(a, b):
        if not a and not b:
            return True
        if not a or not b:
            return False
        return (a.dado == b.dado and
        nos(a.esq, b.dir) and nos(a.dir, b.esq))

    return nos(raiz.esq,raiz.dir)

arvore = ArvoreBinaria(1, ArvoreBinaria(2, ArvoreBinaria(3), ArvoreBinaria(4)),
    ArvoreBinaria(2, ArvoreBinaria(5), ArvoreBinaria(3))
)

print(verificaSimetria(arvore))  # True




