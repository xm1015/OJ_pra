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
vector<int> sortArray(vector<int>& nums)
{

}



