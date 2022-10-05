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