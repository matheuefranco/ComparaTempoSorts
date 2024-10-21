void counting_sort(int *v, int maior, int tam)
{
    int i;
    int saida[100000], cont[100000];
   // saida = malloc(tam * sizeof(int)); 
   // cont = malloc((maior+1) * sizeof(int)); 
    
    
    for (i = 0; i <= maior; i++)
        cont[i] = 0;//zera cont
        
    for (i = 1; i <= tam; i++)//passo 1
        cont[v[i]]++;// conta numero de ocorrencias
        
    for (i = 1; i <= maior; i++)//passo 2
        cont[i] +=  cont[i-1]; //muda o C[i] para que ele contenha os indices reais do vetor de B
        
    for (i = tam; i >= 1; i--){// passo 3
        saida[cont[v[i]]] = v[i];
        cont[v[i]]--;
    }
    
    for (i = 1; i <= tam; i++){
        v[i]=saida[i];
	}
}

