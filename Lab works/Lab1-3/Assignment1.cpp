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
        arr=Arr;
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
};
int main()
{
    int *arr= new int[5];
   Array a(5,arr);
   a.CreateArray(5);
   a.traverseArray();
   a.insertElement(2,15);
   a.traverseArray();
   a.deleteElement(3);
   a.traverseArray();
   if(a.searchElement(3)==-1) cout<<"No match found\n";
   else cout<<"The element is "<<a.searchElement(4)<<endl;
    return 0;
}