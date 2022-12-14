#include "include/algorepo.h"
#include "include/testcase.h"
using namespace std;


// 455.Assign Cookie
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while (child < (int)g.size() && cookie < (int)s.size()) {
        if (g[child] <= s[cookie++])
            ++child;
    }
    return child;
}

int test_455()
{
    vector<int> children = {1, 2};
    vector<int> cookies = {1, 2, 3};
    printf("number of full-child: %d\n", findContentChildren(children, cookies));

    return 0;
}

// 135.Candy
int candy(vector<int>& ratings) {
    int child_n = ratings.size();
    if(child_n < 1)
        return 0;
    else if(child_n == 1)
        return 1;

    vector<int> cookies(child_n, 1);
    for (int i=1; i < child_n; i++) {
        if ( ratings[i] > ratings[i-1] )
            cookies[i] = cookies[i-1] + 1;
    }
    //pr_vector(cookies);
    for (int i=child_n-2; i >= 0; i--) {
        if ( ratings[i] > ratings[i+1])
            cookies[i] = max( cookies[i+1] + 1, cookies[i]);
    }
    //pr_vector(cookies);

    return accumulate(cookies.begin(), cookies.end(), 0);
}

void test_135()
{
    vector<int> ratings = {1,3,4,5,2};
    candy(ratings);
}

// 435.Non-overlapping Intervals
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  if(intervals.size() < 2)
    return 0;
  
  sort(intervals.begin(), intervals.end(), \
  [](vector<int> a, vector<int> b){
    return a[1] < b[1];
  });

  int erase_total = 0;
  int pivot = intervals[0][1];
  for(int i = 1; i < (int)intervals.size(); i++){
    if(intervals[i][0] >= pivot)
      pivot = intervals[i][1];
    else
      erase_total++;
  }

  return erase_total;
}


// 605.Can Place Flowers
// bool canPlaceFlowers_V1(vector<int>& flowerbed, int n) {
//   int planted = 0;
//   for(int i=0; i < flowerbed.size(); ){
//     if(flowerbed[i] == 1) // pvot is 1
//       i += 2;
//     else if( i == 0 || flowerbed[i-1] == 0){ // behind is 0 or bored
//       if( i+1 > flowerbed.size()-1 || flowerbed[i+1] == 0){  // front is 0 or bored
//         flowerbed[i] == 1;
//         planted++;
//         i += 2;
//       }
//       else{
//         i += 3;
//       }
//     }
//     else{
//       i++;
//     }
//   }
//   return n <= planted;
// }
bool canPlaceFlowers(vector<int>& flowerbed, int n) {

  for(int i=0; i < (int)flowerbed.size(); ){
    if(flowerbed[i] == 1) // pvot is 1
      i += 2;
    else{
      if( i+1 > (int)flowerbed.size()-1 || flowerbed[i+1] == 0){  // front is 0 or bored
        n--;
        i += 2;
      }
      else{ // front is 1
        i += 3;
      }
    }
  }

  return n < 1;
}

// 452. Minimum Number of Arrows to Burst Balloons
int findMinArrowShots(vector<vector<int>>& points)
{
  if(points.size() < 1)
    return 0;

  sort(points.begin(), points.end(), \
  [](vector<int> a, vector<int> b){
    return a[1] < b[1];
  });

  int arrows, pos;

  arrows = 1;
  pos = points[0][1];
  for(int i=1; i < (int)points.size(); i++){
    if(points[i][0] > pos){
      arrows++;
      pos = points[i][1];
    }
  }

  return arrows;
}

// 763. Partition Labels
vector<int> partitionLabels(string s) {
  if(s.length() == 0)
    return {0};

  int last_pos[26];
  for(int i=0; i < (int)s.length(); i++){
    last_pos[s[i] - 'a'] = i;
  }

  vector<int> res;
  int head, tail;

  head = tail = 0;
  for(int i=0; i < (int)s.length(); i++){
    if( i > tail ){
      res.push_back(tail - head + 1);
      head = i;
    }
    tail = max(tail, last_pos[s[i] - 'a']);
  }
  res.push_back(tail - head + 1);

  return res;
}

// 122. Best Time to Buy and Sell Stock II
int maxProfit(vector<int>& prices) {
  int revenu = 0;
  for(int i = 1; i < (int)prices.size(); i++){
    revenu += (prices[i] - prices[i-1]) > 0 ? prices[i] - prices[i-1] : 0;
  }
  return revenu;
}

// 406. Queue Reconstruction by Height
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), \
    [](vector<int> a, vector<int> b){
      if(a[0] != b[0]) return a[0] > b[0];
      if(a[1] != b[1]) return a[1] < b[1];
      return false;
    });

    vector<vector<int>> res;
    // for(int i=people.size()-1; i >= 0; i--){
    //     res.insert(res.begin()+people[i][1], people[i]);
    // }
    pr_vector_2(people);
    for(int i=0; i < (int)people.size(); i++){
        res.insert(res.begin()+people[i][1], people[i]);
    }
    return res;
}

void test_406(){
  vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  reconstructQueue(people);
}

// 665. Non-decreasing Array
bool checkPossibility(vector<int>& nums){
  if(nums.size() < 2)
    return true;

  int count = 2;
  for(uint i = 1; i < nums.size(); i++){
    if(nums[i-1] > nums[i]){
      if(--count <= 0)
        return false;
      if(i == 1 || nums[i-2] <= nums[i])  // ????????????????????????????????????
        nums[i-1] = nums[i];
      else
        nums[i] = nums[i-1];
    }
  }
  return true;
}
void test_665(){
  vector<int> a = {4,2,3};
  checkPossibility(a);
}



