#include "include/algorepo.h"
#include "include/testcase.h"
using namespace std;

// 912. Sort an Array
// Quicksort 快速排序
void quicksort(vector<int>& nums, int left, int right){
  if( left >= right )
    return;

  int l = left, r = right;

  int pos = nums[left];
  while( left < right ){
    while( left < right && nums[right] >= pos )
      right--;
    nums[left] = nums[right--];

    while( left < right && nums[left] <= pos )
      left++;
    nums[right] = nums[left++];
  }
  nums[left] = pos;

  quicksort(nums, l, left-1);
  quicksort(nums, left+1, r);
}

// Mergesort 归并排序
void merge_sort(vector<int>& nums, int left, int right, vector<int>& temp){
  if( left + 1 >= right)
    return;
  
  // divide
  int mid = (right + left) >> 1;
  merge_sort(nums, left, mid, temp);
  merge_sort(nums, mid, right, temp);

  // conquer
  int p = left, q = mid, i = left;
  while(p < mid || q < right){
    if(q >= right || (p < mid && nums[p] <= nums[q])){
      temp[i++] = nums[p++];
    } else {
      temp[i++] = nums[q++];
    }
  }

  for(i = left; i < right; i++){
    nums[i] = temp[i];
  }
}

// Insertsort 插入排序
void insertion_sort(vector<int>& nums){
  for( int i = 0; i < (int)nums.size(); i++){
    for( int j = i; j > 0 && nums[j] < nums[j-1]; j--)
      swap(nums[j], nums[j-1]);
  }
}

// Bubblesort 冒泡排序
void bubble_sort(vector<int>& nums){
  bool swapped;
  for( int i = (int)nums.size(); i > 0; i--){
    swapped = false;
    for( int j = 0; j < i-1; j++){
      if( nums[j] > nums[j+1]){
        swap(nums[j], nums[j+1]);
        swapped = true;
      }
    }
    if(!swapped)
      break;
  }
}

// Selectionsort 选择排序
void selection_sort(vector<int>& nums){
  int min;
  for(int i = 0; i < (int)nums.size()-1; i++){
    min = i;
    for( int j = i+1; j < (int)nums.size(); j++){
      if( nums[j] < nums[min] )
        min = j;
    }
    swap(nums[i], nums[min]);
  }
}



// 215. Kth Largest Element in an Array
bool helper_215_V1(vector<int>& nums, int left, int right, int k)
{
  if( left + 1 >= right )
    return false;
  int first = left, last = right - 1;
  int key = nums[first];
  while( first < last ){
    while( nums[last] <= key && first < last)
      last--;
    nums[first] = nums[last];
    while( nums[first] >= key && first < last)
      first++;
    nums[last] = nums[first];
  }
  nums[first] = key;

  if(first == k)
    return true;
  else
    return helper_215_V1(nums, left, first, k) || helper_215_V1(nums, first+1, right, k);
}
int findKthLargest_V1(vector<int>& nums, int k)
{
  helper_215_V1(nums, 0, nums.size(), k);
  return nums[k];
}

// return the position of pivot
int helper_215(vector<int>& nums, int left, int right, int k)
{
  int first = left, last = right;
  int key = nums[left];
  while( last > first ){
    while( last > first && nums[last] <= key)
      last--;
    nums[first] = nums[last];
    while( first < last && nums[first] >= key)
      first++;
    nums[last] = nums[first];
  }
  nums[first] = key;
  return first;
}
int findKthLargest(vector<int>& nums, int k)
{
  k--;
  int left, right, pos;
  left = 0;
  right = nums.size() - 1;
  while( left < right ){
    pos = helper_215(nums, left, right, k);
    if(pos < k)
      left = pos + 1;
    else if( pos > k )
      right = pos - 1;
    else
      return nums[pos];
  }
  return nums[k];
}
void test_215()
{
  vector<int> nums = {3,2,1,5,6,4};
  cout<<"Kth: "<<findKthLargest(nums, 2)<<endl;
}


// 347. Top K Frequent Elements
vector<int> topKFrequent(vector<int>& nums, int k)
{
  unordered_map<int, int> counts;  // Bucket<order:number, value:frequncy>
  int max_count = 0;
  for( const int & num : nums ){
    max_count = max(max_count, ++counts[num]);
  }

  vector<vector<int>> fre_order(max_count + 1);  // Bucket<order:frequncy, value:number>
  for( const auto & p : counts){
    fre_order[p.second].push_back(p.first);
  }

  vector<int> res;
  for( int i = max_count; i >= 0 && (int)res.size() < k; i-- ){
    for( const auto & num : fre_order[i] ){
      res.push_back(num);
      if( (int)res.size() == k )
        break;
    }
  }
  return res;
}


// 451. Sort Characters By Frequency
string frequencySort_V1(string s)
{
  unordered_map<char, int> freq;
  vector<string> bucket(s.size()+1, "");
  string res;

  // Count frequency of each character
  for(char c: s)
    freq[c]++;
  
  // Put character in frequency bucket
  for(auto& item : freq){
    int n = item.second;
    int c = item.first;
    bucket[n].append(n, c);
  }

  // Form the descending sorted string
  for( int i = s.size(); i > 0; i--){
    if(!bucket[i].empty())
      res.append(bucket[i]);
  }
  
  return res;
}
string frequencySort_V2(string s)
{
  int count[256] = {0};
  for( char c: s)
    count[c]++;

  // in the lamda func, "[&]" allow you to use vars in main body
  sort(s.begin(), s.end(), [&](char a, char b){
    return count[a] > count[b] || (count[a]==count[b] && a < b);
  });

  return s;
}


// 75. Sort Colors


