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

// Insertsort 插入排序
void insertion_sort(vector<int>& nums){
  for( int i = 0; i < nums.size(); i++){
    for( int j = i; j > 0 && nums[j] < nums[j-1]; j--)
      swap(nums[j], nums[j-1]);
  }
}

// Bubblesort 冒泡排序
void bubble_sort(vector<int>& nums){
  bool swapped;
  for( int i = nums.size(); i > 0; i--){
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
  for(int i = 0; i < nums.size()-1; i++){
    min = i;
    for( int j = i+1; j < nums.size(); j++){
      if( nums[j] < nums[min] )
        min = j;
    }
    swap(nums[i], nums[min]);
  }
}


vector<int> sortArray(vector<int>& nums)
{

}



