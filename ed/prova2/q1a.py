#Melhor caso: O(n); Pior Caso: O(n^2)
lista1 = [8,3,1,5,2]
#lista1 = list(input().split(" "))
def insertion_sort(lista1):
    for i in range(1, len(lista1)):
        chave = lista1[i]
        j = i - 1
        #move elementos maiores que a chave para a direita

        while j >= 0 and lista1 [j] > chave:
            lista1[j+1] = lista1[j]
            j -= 1
        lista1[j+1] = chave
    return lista1
print(insertion_sort(lista1))
