#include<iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList<int>myList;
    myList.insertFront(4);
    myList.insertFront(3);
    myList.insertFront(2);
    // myList.display();
    myList.insertAtposition(1,10);
    myList.display();
    cout<<"Length "<<myList.getLength()<<endl;
    cout<<"search result = "<<myList.search(15);
}