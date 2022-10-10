#include"include/algorepo.h"
#include"include/testcase.h"
using namespace std;

// 69. Sqrt(x)
int mySqrt_V1(int x){
    if(!x) return 0;
    
    long left = 1, right = x, mid, s;
    while(left <= right){
        mid = (left + right) >> 1;
        s = x / mid;
        if( s < mid )
            right = mid - 1;
        else if( s > mid )
            left = mid + 1;
        else
            return mid;
    }

    return right;
}
int mySqrt_V2(int x){  // 数学方法，降维打击
    long s = x;
    while( s*s > x )
        s = (s + x/s) / 2;
    return s;
}