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
        #

        #if endereco not in lista:
           #return None

        pass
