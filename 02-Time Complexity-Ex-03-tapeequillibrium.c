
#include <limits.h>
#include <stdlib.h>
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, diff;
    int minSum = INT_MAX, before, after = 0;
    
    for (i=0;i<N;i++) {
        after += A[i];
    }

    before = 0;
    for (i=0;i<N-1;i++) {
        before += A[i];
        after  -= A[i];
        diff = abs (after - before);
        if (minSum > diff) {
            minSum = diff;
        }
    }
    return minSum;
}



int main()
{
	int a[] = {-2,-3,-4,-1};
	printf("%d", solution(a,4));
	return 0;
}
