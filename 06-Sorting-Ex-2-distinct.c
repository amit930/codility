#include <stdlib.h>
int cmp (const void * p1, const void *p2) 
{
    return *(int *)p1 - *(int *)p2;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, count = 0;
    
    qsort(A, N, sizeof(int), cmp );
    for (i=0;i<N;i++) {
        while (i<N && (A[i] == A[i+1])) i++;
        count++;
    }
    return count;
}

int main()
{
  int a[] = {2, 1, 1, 2, 3, 1};
  printf ("%d", solution(a, 6);
  return 0;
}
