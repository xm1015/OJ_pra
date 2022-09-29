#include "include/algorepo.h"
using namespace std;


// 455.Assign Cookie
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while (child < g.size() && cookie < s.size()) {
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
    if(ratings.size() < 1)
        return 0;
    else if(ratings.size() == 1)
        return 1;

    vector<int> cookies(ratings.size(), 1);
    for (int i=1; i < ratings.size(); i++) {
        if ( ratings[i] > ratings[i-1] )
            cookies[i] = cookies[i-1] + 1;
    }
    //pr_vector(cookies);
    for (int i=ratings.size()-2; i >= 0; i--) {
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
  for(int i = 1; i < intervals.size(); i++){
    if(intervals[i][0] >= pivot)
      pivot = intervals[i][1];
    else
      erase_total++;
  }

  return erase_total;
}
