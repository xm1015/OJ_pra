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
    nums[left] = nums[right];

    while( left < right && nums[left] <= pos )
      left++;
    nums[right] = nums[left];
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


vector<int> sortArray(vector<int>& nums)
{

}



