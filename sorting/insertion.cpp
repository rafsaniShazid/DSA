#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>&arr)
{
    int n=arr.size(); int j;
    for(int i=0;i<n;i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
vector<int> generate_array(int size){
    vector<int> vec(size);
    srand(time(NULL));
    for(int i=0;i<size;i++) vec[i]=rand()%size;
    return vec;
}
int main(){
    srand(time(NULL));
    int number =rand()%10000;
    vector<int> vec=generate_array(number);
    auto t1=chrono::high_resolution_clock::now();
    insertionSort(vec);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::
    microseconds>(t2-t1).count();
    cout<<"Execution time: "<<duration<<" microseconds"<<endl;
    for(auto i:vec) cout<<i<<" ";
    return 0;
}