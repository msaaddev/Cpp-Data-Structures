#include <iostream>
#include "clist.cpp"
using namespace std;

int main()
{
    cList list;
    cNode node;

    //Checking if the LINKED LIST is empty by using isNotEmpty function
    cout << "This is a check to see if the linked list is empty by using isNotEmpty function. " << endl;

    if (list.isNotEmpty())
    {
        cout << "Linked list is not empty." << endl;
    }
    else
    {
        cout << "Linked list is Empty." << endl;
    }
}