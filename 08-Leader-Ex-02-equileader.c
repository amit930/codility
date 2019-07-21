#include <string.h>

int findLeader(int *A, int st, int end)
{
    int i, leader = -1, count = 0;
    for (i=st;i<end;i++) {
        if (count == 0) {
            leader = A[i];
            count = 1;
        } else if (leader == A[i]) count++;
        else count--;
    }
    count = 0;
    for (i=st;i<end;i++) {
        if (A[i] == leader) count++;
    }
    if (count > (end-st)/2) return leader;
    return -1;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, lstOccurLdr, leaderCount, runningLeaderCnt, equileaders, leader;
    int hash[N];
    leaderCount = 0;
    lstOccurLdr = 0;
    runningLeaderCnt = 0;
    equileaders = 0;
    leader = findLeader(A, 0, N);
    if (leader == -1) return 0;
    memset(hash, 0, sizeof(hash));
    for(i=0;i<N;i++) {
        if (leader == A[i]) {
            leaderCount++;
            hash[i] = leaderCount;
        }
    }
    
    /* Store the 'leaders count' alongwith the index they are present in a hash map (in case of C++, Java)or
       use an array of hash[sizeof(input_arr)] and memset it with 0 */
    for(i=0;i<N;i++) {
        if(leader == A[i]) {
            lstOccurLdr = i;
            runningLeaderCnt = hash[lstOccurLdr];
        } else if (hash[lstOccurLdr] != 0) {
            runningLeaderCnt = hash[lstOccurLdr];
        }
        if(runningLeaderCnt > ((i+1)/2)) {
            if ((leaderCount - runningLeaderCnt) > ( (N-(i+1)) / 2 ) ) {
                equileaders++;
            }             
        }
    }
    return equileaders;
}
