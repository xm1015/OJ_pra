#include"include/algorepo.h"
#include"include/testcase.h"
using namespace std;

// 167. Two Sum II
// vector<int> twoSum_V1(vector<int>& numbers, int target){
//   int i = 0, j = numbers.size()-1;
//   int diff;
//   while( i < j ){
//     diff = target - numbers[i];
//     for(; j > i; j--){
//       if( diff < numbers[j] )
//         continue;
//       else if( diff > numbers[j] )
//         break;
//       else
//         return vector<int>{i+1, j+1};
//     }
//     i++;
//   }
//   return NULL;
// }
vector<int> twoSum_V2(vector<int>& numbers, int target){
  int i = 0, j = numbers.size()-1, diff;

  while( i < j ){
    diff = target - numbers[i];
    if( diff < numbers[j] )
      j--;
    else if( diff > numbers[j] )
      i++;
    else
      break;
  }

  return vector<int>{i+1, j+1};
}

// 76. Minimum Window Substring
string minWindow(string s, string t){
  vector<int> chars(128, 0);
  vector<bool> flags(128, false);

  // 
  for(int i=0; i<t.size(); i++){
    flags[t[i]] = true;
    ++chars[t[i]];
  }

  //
  int count = t.size();
  int l = 0, l_min = 0, min_size = s.size()+1;
  for(int r=0; r < s.size(); r++){
    if(flags[s[r]]){
      if(--chars[s[r]] >= 0){
        count--;
      }

      // Try to move the left_bored
      while( count == 0 ){
        if(r - l + 1 < min_size){
          min_size = r-l+1;
          l_min = l;
        }

        if(flags[s[l]] && ++chars[s[l]] > 0){
          count++;
        }

        l++;
      }
    }
  }
  return min_size > s.size() ? "" : s.substr(l_min, min_size);
}


// 633. Sum of Square Numbers
// bool judgeSquareSum_V1(int c){
//   if( c < 6 && c != 3 ){
//     return true;
//   }
//   double l, r;
//   l = 0;
//   r = c >> 1;
//   while( l <= r ){
//     if( l*l + r*r > c )
//       r--;
//     else if( l*l + r*r < c )
//       l++;
//     else
//       return true;
//   }
//   return false;
// }
bool judgeSquareSum_V2(int c){
  long l, r;
  l = 0;
  r = sqrt(c);

  while( l <= r ){
    if( l*l + r*r > c )
      r--;
    else if( l*l + r*r < c )
      l++;
    else
      return true;
  }

  return false;
}

// 680. Vaild Palindrome II
bool helper(bool life, string s, int left, int right){
  while( left < right ){
    if( s[left] == s[right] ){
      left++;
      right--;
    } else {
      if( life )
        return helper(false, s, left+1, right) || \
               helper(false, s, left, right-1);
      else
        return false;
    }
  }
  return true;
}
bool validPalindrome(string s){
  return helper(true, s, 0, s.size()-1);
}
void test_680(){
  string s = "cbbcc";
  printf("%d\n", validPalindrome(s));
}
