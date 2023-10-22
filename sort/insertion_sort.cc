void insertionsort(int A[], int N) {
  for(int i = N-1; i > 0; i--)
    if (A[i] < A[i-1]) {
      swap(A[i],A[i-1]);
    }

  for(int i = 2; i <= N-1; i++) {
    int j = i;
    int v = A[i];
    while(v < A[j-1]) {
      A[j] = A[j-1]; j--;
    }
    A[j] = v;
  }
}

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 

        /* Move elements of arr[0..i-1], that are 
        greater than key, to one position ahead 
        of their current position */
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}
