#include <stdlib.h>

struct Results {
  int * A;
  int N; // Length of the array
};

struct Results solution(int A[], int N, int K) {
    struct Results result;
    int i, j, tmp;
    // write your code in C99 (gcc 6.2.0)
    if (N==K) goto end;
    
    for(i=N-1; i>=N-K; i--) {
        tmp = A[N-1];
        for (j=N-1;j>0;j--)
            A[j] = A[j-1];
        A[0] = tmp;
        
    }
    
end:
    result.A = A;
    result.N = N;
    return result;
}

int main(void)
{
  int a[] = {1,2,3,4,5,6};
  struct Results r;
  r = solution(a, 6, 2);
  for (i=0; i<r.N; i++) {
    printf ("%d", r.A[i]);
  }
  return 0;
}
