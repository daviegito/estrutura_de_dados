#Melhor caso: ; Pior caso:
lista = list(input().split(" "))
def bubbleSort(lista):
    for passnum in range(len(lista) - 1, 0, -1):
        for i in range(passnum):
            if lista[i] > lista[i+1]:
                lista[i], lista[i + 1] = lista[i + 1], lista[i]
    return lista

print(bubbleSort(lista))
