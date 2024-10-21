#include <stdlib.h>
long long int qtdM=0;
void merge(int vec[], int vecSize) {
    int mid;
    int i, j, k;
    int* tmp;
    
    tmp = malloc(vecSize * sizeof(int));
    if (tmp == NULL) {
        exit(1);
    }
    
    mid = vecSize / 2;
    
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < vecSize) {
    	qtdM++;
        if (vec[i] < vec[j]) {
            tmp[k] = vec[i];
            ++i;
            qtdM++;
        }
        else {
            tmp[k] = vec[j];
            ++j;
        }
        ++k;
    }
    
    if (i == mid) {
        while (j < vecSize) {
            tmp[k] = vec[j];
            ++j;
            ++k;
            qtdM++;
        }
    }
    else {
        while (i < mid) {
            tmp[k] = vec[i];
            ++i;
            ++k;
            qtdM++;
        }
    }
    
    for (i = 0; i < vecSize; ++i) {
        vec[i] = tmp[i];
        qtdM++;
    }
    
    free(tmp);
}

int mergeSort(int vec[], int vecSize) {
    int mid;
    
    if (vecSize > 1) {
        mid = vecSize / 2;
        mergeSort(vec, mid);
        mergeSort(vec + mid, vecSize - mid);
        merge(vec, vecSize);
    }
    return qtdM;
}
