#include <stdlib.h>

int solution(int X, int Y, int D) {
    // write your code in C99 (gcc 6.2.0)
    int DIFF = (Y-X);
    int ans = (DIFF % D);
    return (ans == 0) ? (DIFF / D) : ((DIFF / D) + 1);
}

int main ()
{
  printf("%d\n", solution(10,85,30);
}
