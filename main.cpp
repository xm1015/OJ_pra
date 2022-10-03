#include "algorepo/include/algorepo.h"
#include "algorepo/include/testcase.h"
using namespace std;

int main()
{
    //test_406();
    vector<int> a={1,2,3};
    a.insert(a.begin()+4, 9);
    pr_vector(a);
    return 0;
}