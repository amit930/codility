#include <string.h>

struct Results solution(int N, int A[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int *counter;
    int i,j, maxCounter = 0;
    
    counter = (int *) malloc (sizeof(int)*N);
    memset(counter, 0, sizeof(int)*N);
    for (i=0;i<M;i++) {
        if (A[i] < 1) continue;
        if (A[i] == N+1) {
            for(j=0;j<N;j++) counter[j] = maxCounter;
        } else {
            counter[A[i]-1]++;
            if (maxCounter<counter[A[i]-1]) maxCounter = counter[A[i]-1];
        }
    }
    
    result.C = counter;
    result.L = N;
    return result;
}

//driver program to be updated later
