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