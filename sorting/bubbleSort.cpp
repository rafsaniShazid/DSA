#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& arr)
{
    int len=arr.size(); bool swapped;
    for(int i=0;i<len-1;i++){
        swapped=false;
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            } 
        }
        if(swapped==false) break;
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
    bubbleSort(vec);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::
    microseconds>(t2-t1).count();
    for(int i:vec) cout<<i<<" ";
    cout<<"Execution time: "<<duration<<" microseconds"<<endl;
    return 0;
}