#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void* b)
{
    return *(int *)a - *(int *)b;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    
    if (N==0) return 0;
    
    qsort(A, N, sizeof(int), cmp);
    
    for (i=0;i<N;i++) {
        if (i != A[i]-1) return 0;
    }
    
    return 1;
}

int main()
{
  int a[] = {4,1,3,2};
  printf("%d", solution(a, 4));
  return 0;
}
