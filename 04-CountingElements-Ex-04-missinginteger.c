#include <limits.h>

int cmp( const void* p, const void* q)
{
    return ( *(int *)p - *(int *)q );
}

int solution(int A[], int N) {    
	int i, ans = 1;
  
  qsort(A, N, sizeof(int), cmp);
	if (A[0] > 1) return 1;
	if (A[0] == 1 && N == 1) return 2;
	
	for (i=0;i<N-1;i++) {
    if (A[i] < 0) continue; //negative
    if (A[i+1] == 1 + A[i]) { //1,2,3,4...... 
			ans = ans > A[i+1] ? A[i+1] : ans;
			ans = A[i+1] + 1;
		} else if (A[i+1] == A[i]) { //1,2,2,3,3,4
			ans = ans > (A[i+1] + 1 ) ? A[i+1] + 1 : ans;
		} else { //1,2,4,5,6
      ans = ans > (A[i] + 1 ) ? A[i]+1 :  ans;
      break;
    }
  }
  return ans;
}

int main ()
{
  int p [] = { 37, 6, -7, 41, -23, 15, 9, -14, -18, 1, -13, -22, 25, -43, 24};
	//int p[] = { 1,3,6,4,1,2 };
	//int p[] = {2,3,4,5};
	//int p[] = {1,2,3};
	printf ( "\n%d\n", solution (p,15));
	return 0;
}
