long long int qtdQ=0;
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b=temp;
}// fim troca

int particao(int v[], int ini, int f){
  int pivot,e=ini-1,d=f+1,i;
  pivot=v[(ini+f)/2];
  while(e<d){
	 do{
     	d--;
     	qtdQ++;  
	 }while(v[d]>pivot);
	 do{
     	 e++;
     	 qtdQ++; 
	  }while(v[e]<pivot);
     if(e<d){
     	qtdQ++;
       swap(&v[e],&v[d]);
       }// fimif
  }// fim while
  return d;
}// fim ordena

int quicksort (int v[], int pri, int ultimo) {
  int meio;
  if (pri < ultimo) {
    meio = particao (v, pri, ultimo);
    quicksort (v, pri, meio);
    quicksort (v, meio+1, ultimo);
  }
  return qtdQ;
}
