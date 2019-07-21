#include <stdlib.h>
#include <stdio.h>


/* Read more about it here:
 * https://www.hackerearth.com/practice/notes/abhinav92003/why-output-the-answer-modulo-109-7/
 */
#define MODULO_NUM 1000000007

 /* Handle Int Overflow (HIO) */
#define HIO(p) (p % MODULO_NUM)

int cmp (const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    qsort(A, N, sizeof(int), cmp);
    for (i=0;i<N-2;i++) {
        if ( ((HIO(A[i]) + HIO(A[i+1])) > HIO(A[i+2])) &&
             ((HIO(A[i]) + HIO(A[i+2])) > HIO(A[i+1])) &&
             ((HIO(A[i+1]) + HIO(A[i+2])) > HIO(A[i])) )
             return 1;
    }
    return 0;
}

int main()
{
  int a[] = {10,2,5,1,8,20};
  printf ("%d\n", solution(a, 6));
  return 0;
}
