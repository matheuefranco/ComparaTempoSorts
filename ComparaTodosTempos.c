#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts/bibliotecaOrdenacaoSimples.h"
#include "sorts/heapsort.h"
#include "sorts/quicksort.h"
#include "sorts/mergesort.h"
#include "sorts/counting.h"
#include "sorts/shellsort.h"

int main(){
	int i,n,*vB,*vS,*vI,*vq,*vm,*vh,*vc,*vsh;
	long long r;
	float ini,fim, tempo;
	printf("Qtde de elementos:");
	scanf("%d",&n);
	vB = malloc(sizeof(int)*n);
	vS = malloc(sizeof(int)*n);
	vI = malloc(sizeof(int)*n);
	vq = malloc(n * sizeof(int));
	vm = malloc(n * sizeof(int));
	vh = malloc(n * sizeof(int));
	vc = malloc(n * sizeof(int));
	vsh = malloc(n * sizeof(int));
	gera(vB,n);
	for(i=0;i<n;i++){
		vS[i]=vB[i];
		vI[i]=vB[i];
		vq[i]=vB[i];
		vh[i]=vB[i];
		vm[i]=vB[i];
		vc[i]=vB[i];
		vsh[i]=vB[i];
	}// fim for copia
	//printVet(vB,n);
	//printVet(vS,n);
//	printVet(vI,n);
/*    printf("Executando Bubble Sort\n");
	ini = clock();
	bSort(vB,n);
	fim=clock();
    tempo= (fim-ini)/1000;
    printf("Tempo:%.3f - Comp:%d\n",tempo,cb);
    //-----------------------
    printf("Executando Selection Sort\n");
	ini = clock();
	selectionSort(vS,n);
	fim=clock();
    tempo= (fim-ini)/1000;
    printf("Tempo:%.3f - Comp:%d\n",tempo,cs);
    //------------------------
    printf("Executando Insertion Sort\n");
	ini = clock();
	iSort(vI,n);
	fim=clock();
    tempo= (fim-ini)/1000;
    printf("Tempo:%.3f - Comp:%d\n",tempo,ci);
    */
		// quicksort
	ini=clock();  
	r=quicksort(vq,0,n-1);
	fim=clock();
	tempo=fim-ini;
	printf("Quantidade de comparacoes QSort:%llu\n",r);
	printf("Tempo decorrido(segundos) QSort: %.6f\n",tempo/1000);
	
	// mergesort
	ini=clock();  
	r=mergeSort(vm,n);
	fim=clock();
	tempo=fim-ini;
	printf("Quantidade de comparacoes MergeSort:%llu\n",r);
	printf("Tempo decorrido(segundos) MergeSort: %.5f\n",tempo/1000);
	
			// heapsort
	ini=clock();  
	r=heapsort(vh,n);
	fim=clock();
	tempo=fim-ini;
	printf("Quantidade de comparacoes HeapSort:%llu\n",r);
	printf("Tempo decorrido(segundos) HeapSort: %.5f\n",tempo/1000);
	
	// Shell
	ini=clock();  
	r=shellSort(vsh,n);
	fim=clock();
	tempo=fim-ini;
	printf("Quantidade de comparacoes ShellSort:%llu\n",r);
	printf("Tempo decorrido(segundos) ShellSort: %.5f\n",tempo/1000);
	
	// couting
	ini=clock();  
	counting_sort(vc,50,n);
	fim=clock();
	tempo=fim-ini;
	printf("Tempo decorrido(segundos) Counting: %.5f",tempo/1000);
	return 0;
}


