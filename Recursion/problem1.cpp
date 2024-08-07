// print 1 to N linearly

// #include<bits/stdc++.h>
// using namespace std;
// void print(int i,int n)
// {
//     if(i>n) return;
//     cout<<i<<" ";
//     print(i+1,n);
// }
// int main()
// {
//     print(1,4);
//     return 0;
// }

// print N to 1
#include<bits/stdc++.h>
using namespace std;
void print(int i,int n)
{
    if(i<n){return;}
    cout<<i<<" ";
    print(i-1,n);
}
int main()
{
    print(4,1);
    return 0;
}