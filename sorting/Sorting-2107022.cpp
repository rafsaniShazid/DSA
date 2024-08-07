#include<bits/stdc++.h>
using namespace std;
vector<int> generate_array(int size){
    vector<int> vec(size);
    srand(time(NULL));
    for(int i=0;i<size;i++) vec[i]=rand()%size;
    return vec;
}

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
class heap{
public:
    int arr[100];
    int size=0;
    void insertion(int val){
        size++;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{ return;}
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deletion(){
        if(size==0)
        {cout<<"Nothing to delete"<<endl;
        return;}
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{ return;}
        }
    }
};
void heapify(int arr[],int n,int i){
    int left=2*i;
    int right=2*i+1;
    int largest=i;
    if(largest<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(largest<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
void insertionSort(vector<float>&arr)
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
// void insertionSort(vector<int>&arr)
// {
//     int n=arr.size(); int j;
//     for(int i=0;i<n;i++){
//         j=i;
//         while(j>0 && arr[j-1]>arr[j])
//         {
//             swap(arr[j-1],arr[j]);
//             j--;
//         }
//     }
// }
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<float> b[n];

    // Find the maximum value in the input array
    float maxVal = *max_element(arr.begin(), arr.end());

    // Determine the scaling factor to fit values into the range [0, n)
    float scaleFactor = (n - 1) / maxVal;

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int biased = arr[i] * scaleFactor;
        b[biased].push_back(arr[i]);
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        //insertionSort(b[i]);
    }

    // Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}
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
void mergeSort(vector<int>& arr,int low,int high)
{
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
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
int main(){
    srand(time(NULL));

    // number is the randomly generated size of the array
    // between 10000.
    int number =rand()%10000;
    vector<int> vec=generate_array(number);
    
    // for bucketSort floating array
    vector<float> arr={.15,.17,.25,.79,.67,.37,.57,49,.28,.73};
    // chrono library is used to calculate execution time.
    auto t1=chrono::high_resolution_clock::now();
    // Sorting functions will be called from here.

    //bucketSort(vec);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::
    microseconds>(t2-t1).count();
    cout<<"Execution time: "<<duration<<" microseconds"<<endl;
    // Sorted output will be shown from here.
    // for(int i:arr) cout<<i<<" ";
    return 0;
}