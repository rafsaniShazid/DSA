// print from 1 to N. using i+1 isn't allowed

// #include<bits/stdc++.h>
// using namespace std;
// void print(int i,int n)
// {
//     if(i<n) return;
//     print(i-1,n);
//     cout<<i<<" ";
// }
// int main()
// {
//     print(4,1);
//     return 0;
// }

// print from N to 1

#include<bits/stdc++.h>
using namespace std;
void print(int i,int n)
{
    if(i>n) return;
    print(i+1,n);
    cout<<i<<" ";
}
int main()
{
    print(1,4);
    return 0;
}