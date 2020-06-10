#include <limits.h>
int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    if(H.size() == 0) return 0;
    if(H.size() == 1) return H[0];
    int i;
    int lprx[H.size()], rprx[H.size()];
    int leftmax, rightmax;
    leftmax = rightmax = INT_MIN;
    
    for(int i=0;i<H.size();i++) {
        leftmax = max(leftmax, H[i]);
        lprx[i] = leftmax * (i+1);
    }
    for(int i=H.size()-1;i>=0;i--) {
        rightmax = max(rightmax, H[i]);
        rprx[i] = rightmax * (H.size()-i);
    }
    /* Upto here logic similar to find maximum sum of two disjoint subarrays in array */
    
    /* Count min area--> leftprx[0] + rprx[1], leftprx[1] + rprx[2],......,  leftprx[n-2] + rprx[n-1]: n = H.size()
       You can also print the lprx[] and rrpx[] to understand better the logic */
    int minArea = INT_MAX;
    for(i=0;i<H.size()-1;i++) {
        minArea = min(minArea, lprx[i] + rprx[i+1]);
    }
    return minArea;
}
