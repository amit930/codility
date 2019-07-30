#include <stdlib.h>

int cmp(const void *a, const void *b) 
{
    return *(int *)a - *(int *)b;
}
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    
    if (N==0) return 1;
    qsort(A, N, sizeof(int), cmp);
    for (i=0;i<N;i++) {
        if(i != A[i]-1) return i+1;
    }
    /* If we are here, then all elemens are in order so return 'i+1' as N+1 element is missing */
    return i+1;
}

int main()
{
  int a[] = {2,3,1,5};
  printf("%d", solution(a,4));
  return 0;
}
