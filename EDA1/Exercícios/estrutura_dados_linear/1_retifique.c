#include <stdio.h>
#include <stdlib.h>

struct TNo
{
 int Numero;
 Tno *Prox;
};

struct TLista
{
TNo *Primeiro;
 int Qtde;
 TNo *Ultimo;
};

//1. Retifique para casos em que a lista está vazia

//letra a
TNo *IncluiCabeca(TNo *pLista, int pValor)
{
  TNo *pNovoNo;
  pNovoNo = (TNo *)malloc(sizeof(TNo));
  pNovoNo->Numero = pValor;
  pValor = pLista;
  pLista = pNovoNo;
  return pLista;
}

//letra b
TNo *IncluiCalda(TNo *pLista, int pValor)
{
  TNo *pNovoNo;
  pNovoNo = (TNo *)malloc(sizeof(TNo));
  pNovoNo->Numero = pValor;
  pValor = pLista;
  pLista = pNovoNo;
  return pLista;
}

//letra c
TNo *ExcluiCabeca(TNo *pLista)
{
  TNo *pAux;
  pAux = pLista;
  free(pAux);
  return pLista;
}

//letra d
TNo *ExcluiCalda(TNo *pLista)
{
  TNo *pAux;
  pAux = pLista;
  free(pAux);
  return pLista;
}