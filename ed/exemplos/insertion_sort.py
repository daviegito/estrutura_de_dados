#Melhor caso: O(n); Pior Caso: O(n^2)
lista = list(input().split(" "))
def insertion_sort(lista):
    for i in range(1, len(lista)):
        chave = lista[i]
        j = i - 1
        #move elementos maiores que a chave para a direita

        while j >= 0 and lista [j] > chave:
            lista[j+1] = lista[j]
            j -= 1
        lista[j+1] = chave
    return lista
print(insertion_sort(lista))
