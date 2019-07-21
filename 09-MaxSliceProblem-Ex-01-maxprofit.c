#include <stdlib.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, maxProfit = 0, minday = A[0], val;
    for (i=1;i<N;i++) {
        if (minday > A[i]) minday = A[i];
        val = A[i] - minday;
        if (maxProfit < val) maxProfit = val;
    }
    return maxProfit;
}

int main ()
{
  int a[] = {5, 4, 3, 2, 1};
  printf ("%d\n", solution(a, 5);
  return 0;
}
