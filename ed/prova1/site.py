'''
Implemente o método buscar(site) que, dado o nome de um site,
busque o seu endereço correspondente na lista e, ao mesmo tempo,
mova o elemento que contém o nome buscado para o início da lista, de
forma que buscas subsequentes ao mesmo site sejam mais rápidas.
Caso o nome não esteja na lista, o método deve apenas retornar None
'''

class Node:
    def __init__(self, site, endereco):
        self.site = site
        self.endereco = endereco
        self.next = None

class SiteList:
    def __init__(self):
        self.head = None

    def adicionar(self, site, endereco):
        novo = Node(site, endereco)
        novo.next = self.head
        self.head = novo

    def buscar(self, site):
        if self.head is None:
            return None
        if self.head.site == site:
            return self.head.endereco
        anterior = self.head
        atual = self.head.next
        while atual:
            if atual.site == site:
                anterior.next = atual.next
                atual.next = self.head
                self.head = atual
                return atual.endereco
            anterior = atual
            atual = atual.next
        return None

lista = SiteList()
lista.adicionar("google.com", "142.250.190.78")
lista.adicionar("openai.com", "104.18.12.123")
lista.adicionar("github.com", "140.82.113.3")

print(lista.buscar("openai.com"))  # Deve retornar o IP e mover para o topo
print(lista.buscar("linkedin.com"))  # Deve retornar None
