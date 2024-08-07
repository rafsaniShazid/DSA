#include<iostream>
using namespace std;
int insert(int arr[],int size,int element,int index,int cap)
{
    if(size>=cap) return 0;
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}
int del(int arr[],int size,int index,int cap)
{
    for(int i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    return 1;
}
int main()
{
    int arr[100]={1,2,3,4,5}; int size=5;
    display(arr,size);
    // if(insert(arr,5,9,2,100)) { size++;display(arr,size);}
    // else cout<<"Insertion failed\n";
    del(arr,size,2,100);
    size--;
    display(arr,size);
    return 0;
}