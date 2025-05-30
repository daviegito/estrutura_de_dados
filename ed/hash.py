'''
Considere uma tabela de dispersão (hash table) de
tamanho 10, utilizando o método de endereçamento aberto com
sondagem linear (rehash) com pulo 1 para resolver colisões. A função
de dispersão (hash function) usada é h(x) = x % 10. Dada a sequência
de chaves 23, 43, 13, 27, 33, 37 para inserção na tabela, faça:
Insira cada uma das chaves em ordem na tabela de dispersão,
mostrando o estado da tabela após cada inserção. Indique a posição de
cada chave na tabela e explique como a sondagem linear é aplicada em
caso de colisão.
'''
class Tabela:
    def hashfunction(key, size):
        return key % size
    def put(key, size):
        hash[hashfunction(key, size)].append(key)
    def get(key, size):
        return key in hash[hashfunction(key, size)]

hash = {}
for i in range(size):
 hash[i] = []
