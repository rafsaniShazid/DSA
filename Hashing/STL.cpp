#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
std::ios_base::sync_with_stdio(false);
    unordered_map<int,int> m;
    int arr[8]={1,2,5,6,7,1,6,2};
    for(int i=0;i<8;i++)
    {
        m[arr[i]]++;
    }
    for(auto it:m) cout<<it.first<<"->"<<it.second<<endl;
    return 0;
}