#include<iostream>
using namespace std;
int main(){
std::ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int len=s.size();
    int hash[26]={0};
    for(int i=0;i<len;i++){
        hash[s[i]-'a']++;
    }
    while(1)
    {
        cout<<"Enter the character \n";
        char c; cin>>c;
        if(c=='*') break;
        cout<<"Frequency of "<<c<<" is "<<hash[c-'a']<<endl;
    }
    return 0;
}