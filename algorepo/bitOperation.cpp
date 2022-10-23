#include "include/algorepo.h"
#include "include/testcase.h"
#include <stdlib.h>
using namespace std;

// 461. Hamming Distance
int hammingDistance_V1(int x, int y)
{
    int dist = 0;
    x = x ^ y;
    int temp;
    while(x > 0){
        temp = x >> 1;
        dist += (temp << 1) ^ x;
        x = temp; 
    }
    return dist;
}
int hammingDistance_V2(int x, int y)
{
    int dist = 0;
    x = x ^ y;
    while( x > 0 ){
        dist += x & 1;
        x = x >> 1;
    }
    return dist;
}


// 190. Reverse Bits
uint32_t reverseBits_V1(uint32_t n)
{
    uint32_t res = 1;
    for(int i = 0; i < sizeof(uint32_t) * 8; i++){
        res = res << 1;
        res += n & 1;
        n = n >> 1;
    }
    return res;
}