int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    unsigned int count = 0, res = 0;
    N--;
    while (N>=0) {
        if (A[N] == 1) count++;
        else res += count;
        if (res > 1000000000) return -1;
        N--;
    }
    
    return res;
}

int main ()
{
  int a[] = {0,1,0,1,1};
  printf ("%d\n", solution(a,5));
  return 0;
}
