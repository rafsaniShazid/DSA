// #include<bits/stdc++.h>
// using namespace std;
// void add(int i,int sum)
// {
//     if(i<1){
//         cout<<sum; return;
//     }
//     add(i-1,sum+i);
// }
// int main(){
//     add(3,0);
//     return 0;
// }

// functional returns 

// calculating sum
// #include<bits/stdc++.h>
// using namespace std;
// int sum(int n){
//     if(n==0) return 0;
//     return n+ sum(n-1);
// }
// int main(){
//     cout<<sum(3);
//     return 0;
// }

// calculating factorial

// int fact(int n){
//     if(n==1) return 1;
//     return n* fact(n-1);
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     cout<<fact(4);
//     return 0;
// }

//Reverse an array

// #include<bits/stdc++.h>
// using namespace std;
// void reverse(int i,int arr[],int n)
// {
//     if(i>=n/2) return ;
//     swap(arr[i],arr[n-i-1]);
//     reverse(i+1,arr,n);
// }
// int main(){
//     int arr[5]={1,2,3,4,5};
//     reverse(0,arr,5);
//     for(auto &i:arr) cout<<i<<" ";
//     return 0;
// }

// palindrome check
// #include<bits/stdc++.h>
// using namespace std;
// int checkPalindrome(int i,string s,int n)
// {
//     if(i>=n/2) return 1;
//     if(s[i]!=s[n-1-i]) return 0;
//     return checkPalindrome(i+1,s,n);
// }
// int main(){
//     string s; cin>>s;
//     int len=s.size();
//     cout<<checkPalindrome(0,s,len);
//     return 0;
// }