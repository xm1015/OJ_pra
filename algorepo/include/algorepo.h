#ifndef ALGOREPO_H
#define ALGOREPO_H

/**
 * @brief this .h file includes 
 * @date 2022-10-03
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<cmath>
#include<unordered_map>

void pr_vector(std::vector<int>& v);
void pr_vector_2(std::vector<std::vector<int>>& v);
void pr_vector_string(std::vector<std::string>& s);

// special struct
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



#endif