#include<iostream>
using namespace std;
int main(){
std::ios_base::sync_with_stdio(false);
    int arr[7]={1,3,6,2,3,8,1};
    int hashArray[8]={0};
    for(int i=0;i<7;i++){
        hashArray[arr[i]]++;
    }
    int a;
    while(1){
    cout<<"Enter the number : "<<endl;
    cin>>a;
    if(a==-1) break;
    cout<<"Count of "<<a<<" is "<<hashArray[a]<<endl;
    }
    return 0;
}