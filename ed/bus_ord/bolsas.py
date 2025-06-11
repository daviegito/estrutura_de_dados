quant = float(input()) #quantidade de IRAs
iras = list(map(float, quant))
i = 0

for i in range(0, quant, -1):
    if iras[i] > iras[i+1]:
        print(iras)
    else:
        i+=1
