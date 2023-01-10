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

// 415. Add Strings
long helper_415_s2l(string num)
{
  int len = num.length();
  char c;
  long res = 0, pos = 1;
  while(len > 0){
    c = num[--len];
    res += ((c-'0') * pos);
    pos *= 10;
  }
  return res;
}
string helper_415_l2s(long num)
{
  string res;
  int n;
  long pos = 10;
  while(num){
    n = num % 10;
    num /= 10;
    res.insert(res.begin(), (char)(n+'0'));
  }
  if(res.empty())
    res.insert(res.begin(), '0');
  return res;
}
string addStrings_V1(string num1, string num2)
{
  long n1, n2;
  n1 = helper_415_s2l(num1);
  n2 = helper_415_s2l(num2);
  return helper_415_l2s(n1 + n2);
}

// 如果是数组，尽量做“尾插”而不是“头插”，这样效率更高。
// 如涉及顺序问题，插完后，可以使用反转操作。
string addStrings_V2(string num1, string num2)
{
  // Make sure that num1.size > num2.size
  int len1 = num1.length(), len2 = num2.length();
  if(len1 < len2){
    swap(num1, num2);  // swap交换了num1和num2两个指针中存放的值
    swap(len1, len2);
  }
  
  string res;
  int p1=len1-1, p2=len2-1, addbit=0;
  int bit1, bit2;
  while(p2 >= 0){
    bit1 = (int)(num1[p1--] - '0');
    bit2 = (int)(num2[p2--] - '0');
    res.insert(res.begin(), (char)((bit1 + bit2 + addbit)%10 + '0'));
    addbit = (int)(bit1 + bit2 + addbit >= 10);  // Since addbit <=1 in decimal 
  }

  while(p1 >= 0){
    bit1 = (int)(num1[p1--] - '0');
    res.insert(res.begin(), (char)((bit1 + addbit)%10 + '0'));
    addbit = (int)(bit1 + addbit >= 10);
  }

  if(addbit){
    res.insert(res.begin(), (char)('1'));
  }

  reverse(res.begin(), res.end());
  return res;
}


// 326. Power of Three
bool isPowerOfThree_V1(int n)
{
  return n > 0 && 1162261467 % n == 0;
}
bool isPowerOfThree_V2(int n)
{
  return fmod(log10(n) / log10(3), 1) == 0;
}


// 384. Shuffle an Array
class Solution_384 {
  vector<int> origin;
public:
  Solution_384(vector<int>& nums): origin(std::move(nums)){}

  vector<int> reset() {
    return origin;
  }

  vector<int> shuffle() {
    if(origin.empty())
      return {};

    vector<int> shuffled(origin);
    int n = origin.size();
    for( int i = n - 1; i >= 0; --i) {
      swap(shuffled[i], shuffled[rand() % (i+1)]);
    }

    return shuffled;
  }
};


// 528. Random Pick with Weight
class Solution_528 {
  vector<int> weight_sum;
public:
  Solution_528(vector<int>& w): weight_sum(std::move(w)) {
    partial_sum(weight_sum.begin(), weight_sum.end(), weight_sum.begin());
  }

  int pickIndex() {
    int pos = (rand() % weight_sum[weight_sum.size() - 1]) + 1;  // Attention, pos's range is 1~S, not 0~S-1
    return lower_bound(weight_sum.begin(), weight_sum.end(), pos) - weight_sum.begin();
  }

};


// 382. Linked List Random Node
class Solution_382_V1 {
  int len;
  ListNode* head_a;
public:
  Solution_382_V1(ListNode* head) {
    len = 0;
    head_a = head;
    while(head){
      len++;
      head = head->next;
    }
  }

  int getRandom() {
    long pos = rand() % len;
    ListNode* temp = head_a;
    while(pos--){
      temp = temp->next;
    }
    return temp->val;
  }
};

class Sulotion_382_V2 {
  ListNode* head;
public:
  Sulotion_382_V2(ListNode* head): head(head) {}

  int getRandom() {
    int res = head->val;
    ListNode* node = head->next;

    int i = 2;
    while(node){
      if( rand() % i == 0 ){
        res = node->val;
      }
      i++;
      node = node->next;
    }

    return res;
  }
};