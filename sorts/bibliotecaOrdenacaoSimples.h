#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long cb=0,cs=0,ci=0; // int 64 bits
//-------------------------
void troca(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}// fim troca
//------------------------
void gera(int v[], int n){
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	  v[i]=rand()%50;
}
//------------------------
void printVet(int v[], int n){
	int i;
	for(i=0;i<n;i++)
	  printf("%d |",v[i]);
	printf("\n");  
}
//-----------------------
void bSort(int v[],int n){
	int fase,comp;
	for(fase=1;fase<n;fase++){
	  for(comp=0;comp<n-fase;comp++){
	  	cb++; // contando comparacoes
	  	if(v[comp]>v[comp+1])
	  	   troca(&v[comp],&v[comp+1]);
	  }	// fim for comp
	}// fim for fase
} 
//--------------------------------
int selMin(int v[], int ini, int n){
	int i, menor;
	menor = ini;
	for(i=ini+1;i<n;i++){
		cs++;// contando comparacoes
		if(v[i]<v[menor])
		   menor=i;
	}
	return menor;
}
//-------------------------------
void selectionSort(int v[], int n){
	int i,menor;
	for(i=0;i<n-1;i++){
		menor=selMin(v,i,n);
		troca(&v[i],&v[menor]);
	}// fim for
}
//-------------------
void inserir(int v[], int i){
	int eleito,c;
	eleito = v[i];
	c=i-1;
	while(c>=0 && eleito<v[c]){
		ci++;
		v[c+1]=v[c];
		c--;
	}// fim while
	ci++;
	v[c+1]=eleito;
}// fim insert
//----------------------
void iSort(int v[], int n){
	int i;
	for(i=1;i<n;i++){
		inserir(v,i);
	}// fim for
}// fim isort
