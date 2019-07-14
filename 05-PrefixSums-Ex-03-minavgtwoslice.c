#include <float.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int ans = 0, i, minIdx;
    int prf[N];
    
    double avg = 0, minAvg = DBL_MAX;
    
    prf[0] = A[0];
    for(i=1;i<N;i++) {
        prf[i] = prf[i-1] + A[i];
    } 
    minIdx = 0;
    for (i=1;i<N;i++) {
        avg = ((double)(prf[i] - prf[minIdx] + A[minIdx]) / (double) (i-minIdx+1));
        if (minAvg > avg) {
            minAvg = avg;
            ans = minIdx;
        }
        
    		/*  
     		This solution is really good compared to the 2/3 slice solution posted here.
		 		The premise is that once we've calculated an average,	the only thing that 
		 		will lower that average is if we come across a number that is lower than the
		 		minimum average we've calculated so far. Prefix set calculation is used to
		 		efficiently calculate sum between two segments without having to loop through
		 		every element in that segment. – Moataz Elmasry Mar 22 at 11:35 
		 		https://stackoverflow.com/questions/21635397/min-average-two-slice-codility
				*/
     
		 		if (A[i] < minAvg) {
        	minIdx = i;
     		}
    }
    return ans;
}

int main()
{
	int a[] = {4,2,2,5,1,5,8};
	printf("%d", solution(a, 7));
	return 0;
}
