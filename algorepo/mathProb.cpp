#include "include/algorepo.h"
#include "include/testcase.h"
using namespace std;

// 204. Count Primes
// why overflow ???
int countPrimes_V1(int n)
{
  if( n <= 2 )
    return 0;

  vector<bool> prime(n, true);
  int count = n - 2;  // 1 is not prime

  for( int i = 2; i <= n; i++){
    if(prime[i]){
      for( int j = i * 2; j < n; j += i){  // find all multipule of 'i'
        if(prime[j]){
          prime[j] = false;
          count--;
        }
      }
    }
  }

  return count;
}

int countPrimes_V2(int n)
{
  if(n < 2)
    return 0;

  vector<bool> isPrime(n, true);
  int count = 0;
  for(int i = 2; i < n; i++){
    if(isPrime[i] == false) continue;

    count++;
    for(long j = (long)i * i; j < n; j += i){
      isPrime[j] = false;
    }
  }

  return count;
}


// 504. Base 7
string convertToBase7(int num)
{
  int x = abs(num);
  int b;
  string res = "";

  do{
    b = x % 7;
    res = to_string(b) + res;
    x = x / 7;
  }while(x);

  if(num < 0)
    res = "-" + res;

  return res;
}


// 172. Factorial Trailing Zeroes
int trailingZeroes(int n)
{
  int res = 0;
  for(int i = 5; (n/i) > 0; i *= 5){
    res += (n/i);
  }
  return res;
}

