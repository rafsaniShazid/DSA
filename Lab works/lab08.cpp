#include<iostream>
using namespace std;
void max_heapify(int arr[],int i,int n){
int left= 2*i;
int right=2*i+1;
int largest=i;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(left<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        max_heapify(arr,largest,n);
    }
}
void heapify(int arr[],int n){
    for(int i=n/2;i>=0;i--){
        max_heapify(arr,i,n);
    }
}
// void heapSort(int arr[],int n,int arr2[]){
//     int size=n; int i=0;
//     while(size>1){
//         arr2[i]=arr[0];
//         i++;
//         swap(arr[size],arr[0]);
//         size--;
//         heapify(arr,size);
//     }
// }
void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[0]);
        size--;
        heapify(arr,size);
    }
}
void task(int arr[],int val,int n){
    int index=0;
    for(int i=0;i<=n;i++){
        if(arr[i]==val){index=i;}
    }
    for(int i=index;i<n;i++){
        arr[i]=arr[i+1];
    }
    heapify(arr,n-1);
    for(int i=0;i<n;i++ ) cout<<arr[i]<<" ";
}
int main(){
std::ios_base::sync_with_stdio(false);
    int arr[6]={5,12,23,56,89,35};
    heapify(arr,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int arr2[6];
    heapSort(arr,6);
    for(auto i:arr) cout<<i<<" ";
    //task(arr,5,5);
    return 0;
}