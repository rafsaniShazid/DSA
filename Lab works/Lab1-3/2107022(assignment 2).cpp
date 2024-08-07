#include<iostream>
using namespace std;
class Array
{
    int size;
    int *arr;
public:
    Array(int Size=1,int* Arr=NULL)
    {
        size=Size;
        arr=new int[Size];
    }
    void CreateArray(int size)
    {
        arr=new int[size];
        cout<<"Enter "<<size <<" numbers"<<endl;
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
    }
    void insertElement(int index,int value)
    {   if(index>=size) cout<<"invalid index";
        size++;
        for(int i=size-1;i>=index;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[index]=value;
    }
    void deleteElement(int index)
    {
        for(int i=index;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
    }
    int searchElement(int value)
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i]==value) return i;
        }
        return -1;
    }
    void traverseArray()
    {
        for(int i=0;i<size;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
    int binarySearch(int value){
        int low=0,mid,high=(size-1);
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]==value) return mid;
            else if(arr[mid]<value) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int lowerBound(int value){
        int low=0,high=(size-1);
        while(high-low>1){
            int mid=(low+high)/2;
            if(arr[mid]<value) low=mid+1;
            else high=mid;
        }
        if(arr[low]>=value) return low;
        if(arr[high]>=value) return high;
        return -1;
    }
    int upperBound(int value){
        int low=0,high=(size-1);
        while(high-low>1){
            int mid=(low+high)/2;
            if(arr[mid]<=value) low=mid+1;
            else high=mid;
        }
        if(arr[low]>value) return low;
        if(arr[high]>value) return high;
        return -1;
    }
};
int main()
{
    int *arr;
   Array a(5,arr);
   a.CreateArray(5);
   cout<<"Enter the element you wanna search \n";
   int b;cin>>b;
//    cout<<a.binarySearch(b)<<endl;
//    cout<<a.lowerBound(b)<<endl;
   cout<<a.upperBound(b)<<endl;
    return 0;
}