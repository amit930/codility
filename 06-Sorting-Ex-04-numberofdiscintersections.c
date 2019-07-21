#include <stdlib.h>
#include <stdio.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

/* F1: https://www.youtube.com/watch?v=HV8tzIiidSw */

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    int xleft[N],  /* For storing co-ordinates from centre towards X-ve axis */
        xright[N]; /* For storing co-ordinates from centre towards X+ve axis */
    
    int i, leftIdx, nbInter = 0, rightIdx = 0, openCircles = 0, circleClosed = 0;
    
    for (i=0;i<N;i++) {
        xleft[i]  = i - A[i];
        xright[i] = i + A[i];
    }
    
    /* Sort the obvious */
    qsort(xleft, N, sizeof(int), cmp);
    qsort(xright, N, sizeof(int), cmp);
    
    leftIdx = 0;  /* Left array traversal */
    rightIdx = 0; /* Right array traversal */
    
    while (leftIdx<N && rightIdx <N) { /* Until any one array is fully traversed */
        if (xleft[leftIdx] <= xright[rightIdx]) {
            circleClosed = 0;
            openCircles++;
        } else {
           /* If we are here then close a circle and increase 'rightIdx' */
           openCircles--;
           rightIdx++;
           circleClosed = 1;
           continue;
        }
        if (circleClosed == 0 && openCircles > 1) {
            nbInter += openCircles-1;
            if (nbInter > 10000000) return -1;
        }
        leftIdx++;
    }
    return nbInter;
}

int main()
{
  int a[] = {1,5,2,1,4,0};
  printf ("%d\n", solution(a,6));
  return 0;
}
