'''
Uma fila é uma estrutura de dados do tipo FIFO
(First-In, First-Out), ou seja, o primeiro elemento inserido é o primeiro a
ser removido. Implemente os métodos enqueue e dequeue da classe
Fila. A fila deve ser representada internamente por uma tupla. O
método enqueue(elemento) recebe um elemento e o adiciona ao final
da fila e não retorna nada. O método dequeue() remove e retorna o
elemento no início da fila. Se a fila estiver vazia, ele deve retornar None.
'''

class Fila:
    def __init__(self):
        self.fila = ()

    def enqueue(self, elemento):
        self.fila = self.fila + (elemento,)

    def dequeue(self):
        if len(self.fila) == 0:
            return None
        elemento_removido = self.fila[0]
        self.fila = self.fila[1:]
        return elemento_removido

fila_random = Fila()
fila_random.enqueue(5)
fila_random.enqueue(4)
fila_random.enqueue(3)
print(fila_random.dequeue())
