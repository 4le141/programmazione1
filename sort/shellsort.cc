void ShellSort(int A[], int l, int r){
    int h;
    for (h = 1; h <= (r - 1) / 9; h = 3 * h + 1);
    for (; h > 0; h /= 3);
    for (int i = l + h; i <= r; i++){
        int j = i;
        int v = A[i];
        while ((j >= l + h) && (v < A[j - h])) {
            A[j] = a[j - h];
            j = j - h;
        }
        A[j] = v;
    }
}