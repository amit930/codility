#include <string.h>
#include <stdio.h>

int solution(int M, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int hash[M+1];
    int left, right, count;
    
    left = right = count = 0;
    
    memset(hash, 0, sizeof(hash));
    
    while((left < N) && (right < N)) {
        if (hash[A[right]] == 0) {
            hash[A[right]] = 1;
            count += right - left + 1;
            right++;
        } else {
            hash[A[left]] = 0;
            left++;
        }
        if (count > 1000000000) return 1000000000;
    }
    return count;
}

int main()
{
  int a[] = {3,4,5,5,2};
  printf("%d\n", solution(6, a, 5));
  return 0;
}
