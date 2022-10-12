#include "include/algorepo.h"
using namespace std;

void pr_vector(vector<int>& v)
{
    for(int i=0; i < (int)v.size(); i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void pr_vector_2(vector<vector<int>>& v)
{
  for(int i=0; i<(int)v.size(); i++){
    printf("[%d, %d] ", v[i][0], v[i][1]);
  }
  printf("\n");
}

void pr_vector_string(vector<string>& s){
  for(int i=0; i<(int)s.size(); i++){
    cout<<s[i]<<" ";
  }
  printf("\n");
}