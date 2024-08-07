#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int low,int mid,int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right]) {
            temp.push_back(arr[left]); left++;
        }
        else{temp.push_back(arr[right]);right++;}
    }
    while(left<=mid){temp.push_back(arr[left]);left++;}
    while(right<=high){temp.push_back(arr[right]);right++;}
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
vector<int> generate_array(int size){
    vector<int> vec(size);
    srand(time(NULL));
    for(int i=0;i<size;i++) vec[i]=rand()%size;
    return vec;
}
void mergeSort(vector<int>& arr,int low,int high)
{
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main()
{
    srand(time(NULL));
    int number =rand()%100;
    vector<int> vec=generate_array(number);
    auto t1=chrono::high_resolution_clock::now();
    mergeSort(vec,0,number-1);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::
    microseconds>(t2-t1).count();
    cout<<"Execution time: "<<duration<<" microseconds"<<endl;
    for(int i=0;i<number-1;i++)cout<<vec[i]<<" ";
    return 0;
}