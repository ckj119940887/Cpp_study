#include <iostream>
#include <vector>
using namespace std;

/*
vector空间是连续的且可以自动扩展的。

vector<T> v1;
*/

void ShowVec(const vector<int>& x)
{
    //注意这里的const_iterator，因为输入参数是const vector<int>&
    vector<int>::const_iterator it;
    for(it = x.begin(); it != x.end(); ++it)
    {
        cout << *it << endl;
    }
}

int main()
{
    vector<int> v1;
    vector<int> v2(v1);
    vector<int> v3(3, 0);
    v3.push_back(1);
    ShowVec(v3);
    v3.pop_back();
    ShowVec(v3);

    return 0;
}