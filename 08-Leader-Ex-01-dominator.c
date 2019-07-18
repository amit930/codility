#include <stdlib.h>
#include <stdio.h>

/* NOTE: Returns the index of the dominator element 'leader'; the leader of the array can be obtained from the leader variable */
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, count = 0, leader = -1, idx = -1;
    for (i=0;i<N;i++) {
        if (count == 0) {
            leader = A[i];
            count = 1;
        } else if (leader == A[i]) count++;
        else count--;
    }
    count = 0;
    for (i=0;i<N;i++) {
        if (A[i] == leader) {
            count++;
            idx = i;
        }
    }
    if (count > N/2) return idx;
    return -1;
}

int main()
{
    int a[] = {3,4,3,2,3,-1,3,3};
    printf("%d\n", solution(a, 8));
    return 0;
}
