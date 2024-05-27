#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> mapTest;
    mapTest["aaa"] = 100;
    mapTest.insert(map<string,int>::value_type("bbb", 101));
    mapTest.insert(std::pair<string,int>("ccc", 102));
    mapTest.insert(make_pair("ddd", 103));

    map<string, int>::const_iterator it;
    for(it=mapTest.begin(); it != mapTest.end(); ++it)
        cout<<it->second<<endl;

    int n = mapTest["bbb"];
    cout << n << endl;

    return 0;
}