#include <unordered_map>
int solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map <int, int> map;
    int left, right, maxLen = 1;
    left = right = 0;
    map[A[0]] = 1;
    for(right=1;right<A.size();right++) {
        map[A[right]]++;
        maxLen = max(maxLen, map[A[right]]);
        if(right-left+1-maxLen > K) { //maximum no of A[right] entries + K non A[right] entries exceed
            map[A[left]]--;
            left++;
            
        }
    }
    return right-left; //not right-left+1 beacuse 'right' pointer is one more after full loop run
}
