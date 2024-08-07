//Labwork-02,LAB 2106,Data Structures and Algorithms
//Irham-1907093,2022

//sort and binary search

#include<bits/stdc++.h>

using namespace std;

void bubble_sort(int ara[],int n)
{
    int temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(ara[j]>ara[j+1])
            {
                temp=ara[j];
                ara[j]=ara[j+1];
                ara[j+1]=temp;
            }
        }
    }
}

void Binary_search(int ara[],int item,int n)
{
    int left,right,middle,flag=1;
    left=0;
    right=n;

    while(left<=right)
    {
        middle=(left+right)/2;

        if(ara[middle]==item)
        {
            cout<<"Item found at postion : "<<middle+1<<endl;
            flag=0;
            break;
        }
        else if(ara[middle]<item)
            left=middle+1;
        else
            right=middle-1;
    }
    if(flag)
        cout<<"Item not found\n";
}

int main()
{
    int ara[30],n,item;

    cout<<"Enter size of array : ";
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>ara[i];

    cout<<"Elements of array(given) : ";
    for(int i=0; i<n; i++)
        cout<<ara[i]<<" ";
    cout<<"\n";

    bubble_sort(ara,n);

    cout<<"Elements of array(after sorting) : ";
    for(int i=0; i<n; i++)
        cout<<ara[i]<<" ";
    cout<<"\n";

    cout<<"Enter the number you want to search : ";
    cin>>item;

    Binary_search(ara,item,n);

    return 0;

}




