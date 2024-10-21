#include <stdio.h>
#include <stdlib.h>
long long int qtdSh=0;
int shellSort(int vet[], int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i;
            qtdSh++;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
            }
            qtdSh++;
            vet [j] = value;
        }
    }
    return qtdSh;
}
