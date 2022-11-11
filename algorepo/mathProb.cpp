#include "include/algorepo.h"
#include "include/testcase.h"
using namespace std;

// 204. Count Primes
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
