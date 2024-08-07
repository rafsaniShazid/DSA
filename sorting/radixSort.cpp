#include<bits/stdc++.h>
using namespace std;
vector<int> countSort(vector<int>&arr,int pos)
{
    auto max=max_element(arr.begin(),arr.end());
    vector<int> temp(*max+1,0);
    for(auto &i:arr) temp[(i/pos)%10]++;
    int n= *max+1;
    int len=arr.size();
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        if(temp[i]){
            while(temp[i]){
                result.push_back(i);
                temp[i]--;
            } 
        }
    }
    return result;
}
void radixSort(vector<int>&arr){
    auto max=max_element(arr.begin(),arr.end());
    int n= *max+1;

    for(int pos=1;n/pos>0;pos*=10)
    {
        arr=countSort(arr,pos);
    }
}
vector<int> generate_array(int size){
    vector<int> vec(size);
    srand(time(NULL));
    for(int i=0;i<size;i++) vec[i]=rand()%size;
    return vec;
}
int main()
{
    srand(time(NULL));
    int number =rand()%10000;
    vector<int> vec=generate_array(number);
    auto t1=chrono::high_resolution_clock::now();
    radixSort(vec);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::
    milliseconds>(t2-t1).count();
    for(auto i:vec) cout<<i<<" ";
    cout<<"Execution time: "<<duration<<" miliseconds"<<endl;
    return 0;
}