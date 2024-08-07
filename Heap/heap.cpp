#include<iostream>
using namespace std;
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
int main(){
std::ios_base::sync_with_stdio(false);
    heap h;
    h.insertion(5);
    h.insertion(15);
    h.insertion(17);
    h.insertion(25);
    // h.print();
    // h.deletion();
    // h.print();
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    // for(int i=n/2;i>0;i--){
    //     heapify(arr,n,i);
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    //cout<<endl;
    heapSort(arr,n);
        for(int i=1;i<=5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}