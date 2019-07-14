#include <stdlib.h>
int solution(int A, int B, int K) {
    // write your code in C99 (gcc 6.2.0)
    int c1, c2, diff;
    c1 = B/K;
    c2 = A/K;
    diff = c1 - c2;
    if (A%K == 0) diff++;
    return diff;
}

int main (void)
{
  printf ("%d", solution(6,11,2);
  return 0;
}
