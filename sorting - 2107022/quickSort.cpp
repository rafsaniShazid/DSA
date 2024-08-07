#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr,int low,int high)
{
    int pivot=arr[low];
    int left=low;
    int right=high;
    while(left<right)
    {
        while(arr[left]<=pivot && left<=high-1) left++;
        while(arr[right]>pivot && right>=low+1) right--;
        if(left<right) swap(arr[left],arr[right]);
    }
    swap(arr[low],arr[right]);
    return right;
}
void quickSort(vector<int>& arr,int low,int high)
{
    if(low<high)
    {
        int pIndex=partition(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
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
    quickSort(vec,0,number-1);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::
    microseconds>(t2-t1).count();
    cout<<"Execution time: "<<duration<<" microseconds"<<endl;
    for(int i=0;i<number-1;i++)cout<<vec[i]<<" ";
    return 0;
}