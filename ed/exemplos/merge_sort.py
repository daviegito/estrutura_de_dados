#Melhor caso: O(n log n); Pior caso: O(n log n)
lista = list(input().split(" "))
def merge_sort(lista):
    if len(lista) < 2:
        return lista
    meio = len(lista) // 2
    esquerda = merge_sort(lista[:meio])
    direita = merge_sort(lista[meio:])
    return merge(esquerda, direita)

def merge(esquerda,direita):
    lista = []

    while esquerda and direita:
        if esquerda[0] <= direita[0]:
            lista.append(esquerda.pop(0))
        else:
            lista.append(direita.pop(0))

    if esquerda:
        lista.extend(esquerda)
    if direita:
        lista.extend(direita)

    return lista

print(merge_sort(lista))
