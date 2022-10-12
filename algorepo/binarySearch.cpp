#include"include/algorepo.h"
#include"include/testcase.h"
using namespace std;

// 69. Sqrt(x)
int mySqrt_V1(int x){
    if(!x) return 0;
    
    long left = 1, right = x, mid, s;
    while(left <= right){
        mid = (left + right) >> 1;
        s = x / mid;
        if( s < mid )
            right = mid - 1;
        else if( s > mid )
            left = mid + 1;
        else
            return mid;
    }

    return right;
}
int mySqrt_V2(int x){  // 数学方法，降维打击
    long s = x;
    while( s*s > x )
        s = (s + x/s) / 2;
    return s;
}

// 34. Find First and Last Position of Element in Sorted Array
static vector<int> helper_34(vector<int>& nums, int pivot, int target){
    int left, right, mid;
    vector<int> res = {-1, -1};

    left = 0;
    right = pivot;
    while( left <= right ){
        mid = (left + right) >> 1;
        if( nums[mid] == target ){
            if( mid == 0 || nums[mid-1] < target ){
                res[0] = mid;
                break;
            }
            else
                right = mid - 1;
        }
        else if( nums[mid+1] == target ){
            res[0] = mid + 1;
            break;
        }
        else
            left = mid + 1;
    }

    left = pivot;
    right = nums.size()-1;
    while( left <= right ){
        mid = ( left + right ) >> 1;
        if( nums[mid] == target ){
            if( mid == (int)nums.size()-1 || nums[mid+1] > target){
                res[1] = mid;
                break;
            }
            else
                left = mid + 1;
        }
        else if( nums[mid-1] == target ){
            res[1] = mid - 1;
            break;
        }
        else
            right = mid - 1;
    }
    return res;
}
vector<int> searchRange(vector<int>& nums, int target){
    
    int left = 0, right = nums.size()-1;
    int mid;
    while( left <= right ){
        mid = (left + right) >> 1;
        if( nums[mid] == target ){
            return helper_34(nums, mid, target);
        }
        else if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return {-1, -1};
}
void test_34(){
    vector<int> nums = {1,4};
    vector<int> res = searchRange(nums, 4);
    pr_vector(res);
}

// 81. Search in ROtated Sorted Array II
bool search(vector<int>& nums, int target){
  int left=0, right = nums.size()-1;
  int mid;
  while(left <= right){
    mid = (left + right) >> 1;
    if(nums[mid] == target)
      return true;
    else if(nums[left] == nums[mid]){
      // in this situation, we can judge which part is non-decreasing
      // so we just shrink the zone
      left++;
    }
    else if(nums[right] >= nums[mid]){
      // the right part is non-decreasing
      if(target > nums[mid] && target <= nums[right])
        left = mid + 1;
      else
        right = mid - 1;
    }
    else {
      // the left part is non-decreasing
      if(target < nums[mid] && target >= nums[left])
        right = mid - 1;
      else
        left = mid + 1; 
    }
  }
  return false;
}


// 154. Find Minimum in Rotated Sorted Array II
int findMin_V1(vector<int>& nums){
  int m, mid;
  int left = 0, right = nums.size()-1;
  m = nums[left];

  while(left <= right){
    mid = (left + right) >> 1;
    if( nums[left] < nums[right] ){
      // array is already in non-decreasing
      m = min(m, nums[left]);
      break;
    }
    else if( nums[mid] == nums[left]){
      // we can't tell which part is non-decreasing
      m = min(m, nums[mid]);
      left++;
    }
    else if( nums[left] < nums[mid] ){
      // left part is non-decreasing
      left = mid + 1;
    }
    else {
      // right part is non-decreasing
      m = min(m, nums[mid]);
      right = mid - 1;
    }
  }
  return m;
}
int findMin_V2(vector<int> &nums){
    int low = 0, high = nums.size()-1;
    int mid;
    while(low < high){
        mid = (low + high) >> 1;
        if( nums[mid] == nums[high] ){
            high--;
        }
        else if( nums[mid] < nums[high] ){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return nums[low];
}
void test_154(){
  vector<int> nums = {2,2,2,0,1};
  //findMin(nums);
}



