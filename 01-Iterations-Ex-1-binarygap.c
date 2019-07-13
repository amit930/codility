#include <stdlib.h>
#include <string.h>

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
    int a[sizeof(int)*8];
    int size=sizeof(int)*8, i=0, curr, count, checkwithMax = 1;
    
    memset(a, 0, sizeof(int)*8);
    
    curr = 0;
    count = 0;
    while (i < size) {
        a[i] = (N & (1<<i)) >> i;
        i++;
    }
    
	curr = 0;
	count =0;
    for (i=0;i<size;i++) {
    	if(checkwithMax==1 && a[i] == 1) {
			checkwithMax=0;
		} else if(checkwithMax==0 && a[i]==1) {
			if (a[i-1] == 1) {
				continue; 
			}
    		if (curr > count) count = curr;
    		curr=0;
    		checkwithMax=1;
    		if(a[i+1] == 0) {
    			i--;
    			continue;
			}
		} else if (checkwithMax==0 && a[i]==0) {
			curr++;
		}
	}
    //printf ("\nSolution(%d): %d\n", N, count);
	
    return count;
}


int main(void) 
{
	printf("%d\n",solution(9));
	printf("%d\n",solution(27));
	printf("%d\n",solution(243));
	printf("%d\n",solution(23));
	printf("%d\n",solution(5555));
	printf("%d\n",solution(1041));
	return 0;
}
