#include <limits.h>

#define max(p,q) (p>q?p:q)

/* As kadens algorithm requires that the array requires atleast one +ve number
   modified the algorithm to work for -ve numbers (-1000000 to 1000000)  */
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, meh, msf;
    msf = -1000000; 
    meh = -1000000;
    for (i=0;i<N;i++) {
        
        meh = max (A[i], A[i]+meh);
        if (msf < meh) msf = meh;
    }
    return msf;
}

int main()
{
  int a[] = {3,2,-6,0,4};
  printf ("%d", solution(a, 6));
  return 0;
}
