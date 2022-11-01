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


// 342. Power of Four
bool isPowerOfFour_V1(int n)
{
    int mask = 0b10101010101010101010101010101010;
    return n > 0 && !(n & (n-1)) && !(n & mask);
}
bool isPowerOfFour_V2(int n)
{
    // what the fuck???
    return n > 0 && !(n & (n-1)) && !((n - 1) % 3);
}


// 136. Single Number
int singleNumber(vector<int>& nums)
{
    int res = nums[0];
    for( int i = 1; i < nums.size(); i++) {
        res ^= nums[i];
    }
    return res;
}

// 338. Counting Bits
vector<int> countBits_V1(int n)
{
    vector<int> dp(n+1, 0);
    for(int i = 0; i <= n; i++){
        dp[i] = i & 1 ? dp[i-1]+1 : dp[i>>1];
    }
    return dp;
}
vector<int> countBit_V2(int n)
{
    // it just based on the fact that i and i>>1 share the common head
    vector<int> dp(n+1, 0);
    for(int i=1; i <= n; i++){
        dp[i] = dp[i>>1] + (i & 1);
    }
    return dp;
}


// 318. Maximum Product of Word Lengths
int maxProduct(vector<string>& words)
{
    unordered_map<int, int> hash_str;
    int max_prd = 0, mask = 0;
    for(const string & s : words){
        mask = 0;
        int now_size = s.size();
        for(const char & c : s)
            mask |= (1 << (c - 'a'));

        hash_str[mask] = max(hash_str[mask], now_size);

        for( const auto & pair : hash_str ){
            if((pair.first & mask) == 0){
                max_prd = max(max_prd, pair.second * now_size);
            }
        }
    }

    return max_prd;
}


// 268. Missing Number
int missingNumber(vector<int>& nums)
{
    int all = 0, total = nums.size();
    for(int i = 1; i <= total; i++){
        all ^= i;
        all ^= nums[i-1];
    }
    return all;
}


// 693. Binary Number with Alternatin Bits
bool hasAlternatingBits(int n)
{
    if( n & 1 )
        n >>= 1;

    while( n > 0 ){
        if( (n & 3) == 2 ){
            n >>= 2;
            continue;
        } else {
            return false;
        }
    }

    return true;
}


// 476. Number Complement
int findComplement_V1(int num)
{
    int bc = 0;
    int temp = num;
    while(num){
        bc++;
        num >>= 1;
    }
    return num ^ ((1L << bc) - 1);
}
int findCoplement_V2(int num)
{
    unsigned int mask = ~0;
    while( num & mask )
        mask <<= 1;
    return num ^ ~mask;
}

// 260. Single Number III
vector<int> singleNumber_V1(vector<int>& nums)
{
    int aXORb = 0;
    for( const int i : nums)
        aXORb ^= i;
    
    unsigned int diffBit = 1;
    while((aXORb & diffBit) == 0)
        diffBit <<= 1;

    int a=0, b=0;
    for( const int m : nums){
        if(m & diffBit)
            a ^= m;
        else
            b ^= m;
    }

    return vector<int>{a, b};
}
vector<int> singleNumber_V2(vector<int>& nums)
{
    // 注意！这里的aXORb如果用int，在后面减1时可能会溢出！！！
    long aXORb = 0;
    for( const int i : nums)
        aXORb ^= i;
    
    unsigned int diffBit = (aXORb & (aXORb - 1)) ^ aXORb;

    int a=0, b=0;
    for( const int m : nums){
        if(m & diffBit)
            a ^= m;
        else
            b ^= m;
    }

    return vector<int>{a, b};
}