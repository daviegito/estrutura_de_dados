#Melhor caso: O(n log n); Pior caso: O(n log n)
lista1 = [8,3,1,5,2]
#lista = list(input().split(" "))
def merge_sort(lista1):
    if len(lista1) < 2:
        return lista1
    meio = len(lista1) // 2
    esquerda = merge_sort(lista1[:meio])
    direita = merge_sort(lista1[meio:])
    return merge(esquerda, direita)

def merge(esquerda,direita):
    lista1 = []

    while esquerda and direita:
        if esquerda[0] <= direita[0]:
            lista1.append(esquerda.pop(0))
        else:
            lista1.append(direita.pop(0))

    if esquerda:
        lista1.extend(esquerda)
    if direita:
        lista1.extend(direita)

    return lista1

print(merge_sort(lista1))
