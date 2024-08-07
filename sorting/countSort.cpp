#include<bits/stdc++.h>
using namespace std;
void countSort(vector<int>&arr)
{
    auto max=max_element(arr.begin(),arr.end());
    vector<int> temp(*max+1,0);
    for(auto &i:arr) temp[i]++;
    int n= *max+1;
    int len=arr.size();
    vector<int> result;
    for(int i=0;i<n;i++){
        if(temp[i]){
            while(temp[i]){
                result.push_back(i);
                temp[i]--;
            } 
        }
    }
    arr=result;
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
    countSort(vec);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::
    microseconds>(t2-t1).count();
    cout<<"Execution time: "<<duration<<" microseconds"<<endl;
    for(int i:vec) cout<<i<<" ";

    return 0;
}