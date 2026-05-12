#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

bool duplicate(vector<int>& nums)
{
    unordered_map<int, bool> m;
    for(auto& n:nums)
    {
        if(m.find(n)!=m.end()) return true;
        else m[n]=true;
    }
    return false;
}

int main()
{
    vector<int> vec={1,2,3,4,5,6,7,8,2};
    cout<<duplicate(vec)<<endl;
    return 0;
}