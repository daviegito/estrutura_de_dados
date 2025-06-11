from collections import Counter

quant = int(input()) #quantidade de peças
peca = (input().split()) #string com as pecas
i = 0
j = i + 1

for i in range (0, len(peca)):
    while j < len(peca):
        repet = 0
        i+=1
        if peca[i] == peca[j]:
            repet += 1
        else:
            i += 1
print(repet)
