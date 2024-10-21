long long int qtd=0;

void adjust(int a[], int root, int n)
{
	int maxchild, tmp;
    

	while ((2 * root + 1) <= n) {
		maxchild = 2 * root + 1;          // left child
         qtd++;
		if (maxchild < n && a[maxchild] < a[maxchild + 1]) // if have left child and right child, and the right is greater than left
		{	
		   maxchild++; 	              // right child
		   qtd++;
          }
		if (a[root] > a[maxchild]) {
			qtd++;
			break;
			}
		else {
			tmp = a[root];
			a[root] = a[maxchild];
			a[maxchild] = tmp;
			root = maxchild;
		}
	}
}

int heapsort(int a[], int n)
{
	int i, tmp;
	/* build the heap */
	for (i = n/2 - 1; i >= 0; i--)
	{
			    adjust(a, i, n);
			    qtd++;
			}

	/* swap the last record with root, and adjust the heap */
	for (i = n; i >=1; i--) {
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;

		adjust(a, 0, i-1);
		qtd++;
		/* display(a, array_size); */
	}
	return qtd;
}


