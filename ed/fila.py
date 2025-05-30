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
        fila = fila + (elemento,)               
    def dequeue(self):
        if fila != []:
            fila = fila[1:]
            return fila[0]
        else: 
            return None
fila_random = Fila()
fila_random.enqueue((5,4,2,3,4))
fila_random.dequeue()
