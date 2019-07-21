#define max(a,b) (a > b ? a : b)

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    qsort(A,N, sizeof(int), cmp);
    
    /* In case arr[] contains two -ve numbers, they can add to become a poistive
       product greater than the product of last 3 elements after sorting.
       Hence we choose the max of two different product candidates
       */
    
    return (max ( (A[0]*A[1]*A[N-1]) , (A[N-1]*A[N-2]*A[N-3])));
}

int main()
{
  int a[] = {4, -5, -5, 4};
  printf ("%d", solution(a, 4));
  return 0;
}
