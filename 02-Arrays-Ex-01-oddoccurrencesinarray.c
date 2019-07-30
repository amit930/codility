#include <stdlib.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    int res = 0;
    for (i=0; i < N; i++)
        res = res ^ A[i];
    return res;
}

int main()
{
  int a[] = {9,3,9,3,9,7,9};
  printf("%d\n", solution(a, 7);
  return 0;
}
