//Labwork-01,LAB 2106,Data Structures and Algorithms

///code for insetion and deletion operation in an array
//Irham-1907093,6 April,2022

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,pos,item,ara[100],sizee,ops;

    cout<<"Enter size of array : ";
    cin>>sizee;

    cout<<"Enter elements for array : ";
    for(int i=0; i<sizee; i++)
        cin>>ara[i];

    while(1)
    {
        //printing array
        cout<<"Array's current state : \n";
        for(int i=0; i<sizee; i++)
            cout<<ara[i]<<" ";
        cout<<"\n";

        cout<<"Enter operation type,1 for insertion,2 for deletion,0 for exit : \n";
        cin>>ops;

        if(ops==1) //for insertion
        {
            cout<<"Enter element to insert and its position ";
            cin>>item>>pos;

            for(int i=sizee-1; i>=pos-1; i--)
                ara[i+1]=ara[i];

            ara[pos-1]=item;
            sizee++;
        }
        else if(ops==2) //for deletion
        {
            cout<<"Enter element's position to delete : ";
            cin>>pos;

            for(int i=pos-1; i<sizee-1; i++)
                ara[i]=ara[i+1];
            sizee--;
        }
        else //exit
            return 0;
    }

    return 0;
}
//End of code
