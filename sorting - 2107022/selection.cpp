#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]) min=j;
        }
        if(min!=i) swap(arr[i],arr[min]);
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
    selectionSort(vec);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::
    microseconds>(t2-t1).count();
    cout<<"Execution time: "<<duration<<" microseconds"<<endl;
    for(auto i:vec) cout<<i<<" ";

    return 0;
}