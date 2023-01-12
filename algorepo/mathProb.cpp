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


// 168. Excel Sheet Column Title
string convertToTitle(int columnNumber) 
{
  int index;
  string res;
  while(columnNumber--) {
    index = columnNumber % 26;
    columnNumber /= 26;
    res.insert(res.begin(), (char)('A'+index));
  }
  
  return res;
}


// 67. Add Binary
string addBinary(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int a_len = a.size(), b_len = b.size();

  // Make sure a.len >= b.len
  if(a_len < b_len) {
    swap(a, b);
    swap(a_len, b_len);
  }

  string res;
  int pa = 0, pb = 0;
  int temp, t_sum, addbit = 0;

  while( pb < b_len  && pa < a_len ) {
    t_sum = (a[pa++] + b[pb++] - '0' * 2);
    temp = (t_sum + addbit) % 2;
    addbit = (t_sum + addbit) / 2;
    res.push_back('0'+ temp);
  }
  while( pa < a_len ){
    t_sum = a[pa++] - '0';
    temp = (t_sum + addbit ) % 2;
    addbit = (t_sum + addbit) / 2;
    res.push_back('0' + temp);
  }

  if(addbit)
    res.push_back('1');

  reverse(res.begin(), res.end());
  return res;
}


// 238. Product of Array Except Self
vector<int> productExceptSelf_V1(vector<int>& nums)  // Excceed limited time
{
  vector<int> res;
  vector<long> prefix(1,1), suffix(1,1);
  int len = nums.size();

  for(int i = 1; i < len; i++) {
    prefix.insert(prefix.end(), prefix[i-1] * (long)nums[i-1]);
    suffix.insert(suffix.begin(), suffix[0] * (long)nums[len-i]);
  }

  for(int i = 0; i < len; i++) {
    res.push_back(prefix[i] * suffix[i]);
  }

  return res;
}
vector<int> productExceptSelf_V2(vector<int>& nums)
{
  int len = nums.size();
  vector<int> res(len, 1);
  int prefix_product = 1, suffix_product = 1;

  for(int i = 1; i < len; i++) {
    prefix_product *= nums[i-1];
    suffix_product *= nums[len-i];

    res[i] *= prefix_product;
    res[len-i-1] *= suffix_product;
  }

  return res;
}


// 462. Minimum Moves to Equal Array Elements II
int minMoves2_V1(vector<int>& nums)
{
  int len = nums.size();
  vector<long> aver(len, 0);

  sort(nums.begin(), nums.end());

  long prefix_sum = 0, suffix_sum = 0;

  for(int i = 1; i < len; i++) {
    prefix_sum += nums[i-1];
    suffix_sum += nums[len-i];
    aver[i] += i * (long)nums[i] - prefix_sum;
    aver[len-i-1] += suffix_sum - i * (long)nums[len-i-1];
  }

  return (int)*min_element(aver.begin(), aver.end());
}
int minMoves2_V2(vector<int>& nums)
{
  // A fact is: median number is always the best choic for this situation
  int len = nums.size();
  int res = 0;

  // Instead of sorting whole array, just find the median pole is faster
  nth_element(nums.begin(), nums.begin()+len/2, nums.end());
  int median = nums[len/2];

  for(int i = 0; i < len; i++) {
    res += abs(median - nums[i]); 
  }

  return res;
}
