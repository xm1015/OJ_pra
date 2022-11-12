#include "include/algorepo.h"
#include "include/testcase.h"
using namespace std;

// 695. Max Area of Island
int helper_695(vector<vector<int>>& grid, int i, int j){

  if(grid[i][j] == 0)
    return 0;

  grid[i][j] = 0;
  int dire[5] = {-1, 0, 1, 0, -1};
  int area = 1;
  int x, y;
  for(int n = 0; n < 4; n++){
    x = i + dire[n];
    y = j + dire[n+1];
    if(x >= 0 && x < grid.size() && \
       y >= 0 && y < grid[0].size() && \
       grid[x][y] == 1){
      area += helper_695(grid, x, y);
    }
  }

  return area;
}
int maxAreaOfIsland(vector<vector<int>>& grid)
{
  if(grid.empty() || grid[0].empty()) return 0;
  int max_area = 0;
  for( int i = 0; i < grid.size(); i++){
    for( int j = 0; j < grid[0].size(); j++){
      if(grid[i][j] == 1){
        max_area = max(max_area, helper_695(grid, i, j));
      }
    }
  }
  return max_area;
}


// 547. Friend Circles
void helper_547(vector<vector<int>>& map, int ck){
  if(map[ck][ck] == 0)
    return;

  map[ck][ck] = 0;

  for(int i = 0; i < map.size(); i++){
    if(map[ck][i] == 1)
      helper_547(map, i);
  }
}
int findCircleNum(vector<vector<int>>& isConnected)
{
  int pro_num = 0;
  int city_num = isConnected.size();

  for(int i = 0; i < city_num; i++){
    if(isConnected[i][i] == 0)
      continue;

    pro_num++;
    helper_547(isConnected, i);
  }

  return pro_num;
}


// 417. Pacific Atlantic Water Flow
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
  
}