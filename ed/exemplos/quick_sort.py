#Melhor caso: O(n log n); Pior caso: O(n^2)
lista = list(input().split(" "))
def quicksort(lista):
    if len(lista) <= 1:
        return lista
    pivot = lista[len(lista) // 2]
    left = [x for x in lista if x < pivot]
    middle = [x for x in lista if x == pivot]
    right = [x for x in lista if x > pivot]
    return quicksort(left) + middle + quicksort(right)
print(quicksort(lista))

