int separa (int *v, int e, int d) {
  int j = e, k = e;
  while(k<d) {
    if (v[k] <= p) {
      int tmp = v[k];
      v[k] = v[j];
      v[j] = tmp; //guardar a variável temporária
      j++;
    }
    k++;
  }
  int tmp = v[k];
  v[k] = v[j];
  v[j] = tmp;
  return j; //novo pivô
}

void quickselect(int *v, int e, int d, int k) {
  if (e<d) {
    int j = separa(v,e,d);
    if (k<j) quickselect(v,e,j-1,k);
    if (k>j) quickselect(v,j+1,d,k);
  }
}
