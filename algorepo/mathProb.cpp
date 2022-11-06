#include "include/algorepo.h"
#include "include/testcase.h"
using namespace std;

// 204. Count Primes
int countPrimes(int n)
{
  if( n < 2 )
    return 0;

  vector<bool> prime(n, true);
  int count = n - 2;  // 1 is not prime

  for( int i = 2; i <= n; i++){
    if(prime[i]){
      
    }
  }
}