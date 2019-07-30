#include <stdlib.h>
#include <stdio.h>

int solution(char *S)
{
    char stack[strlen(S)+1];
    char curr;
    int top = -1;
    if (*S == '\0') return 1;
    if (strlen(S) == 1) return 0;
    while(*S) {
        if(0) {}
        else if (*S == '(') stack[++top] = *S;
        else if (*S == ')') {
           curr = stack[top--];
           if (*S == ')' && curr != '(') return 0;
        }
        S++;
    }
    if (top != -1) return 0; /* Stack not empty! */
    return 1;
}

int main()
{
  printf("%d\n", solution( "(()(())())" );
  printf("%d\n", solution( "())" );
  return 0;
}
