#include <iostream>
#include "Queue.cpp"
using namespace std;

int main()
{
    cQue queue;
    /*
	This is a check to see if the Queue is empty by using isEmpty function
	*/
    cout << "This is a check to see if the Queue is empty by using isEmpty function. " << endl;
    if (queue.isEmpty())
    {
        cout << "Queue is empty." << endl
             << endl;
    }
    else
    {
        cout << "Queue is not Empty." << endl
             << endl;
    }

    /*
	This is a check to see if the Queue is empty by using isEmpty function.
	*/
    cout << "This is a check to see if the Queue is empty by using isEmpty function." << endl;
    if (queue.isNotEmpty())
    {
        cout << "Queue is not empty." << endl
             << endl;
    }
    else
    {
        cout << "Queue is Empty." << endl
             << endl;
    }

    /*
	This is a check to see all the elements present in the queue by printing them.
	*/
    cout << "This is a check to see all the elements present in the queue by printing them." << endl;
    queue.print();
    cout << endl;

    /*
	Declaring a node and setting the data
	*/
    cNode *ptr = new cNode(102);
    /*
	Pushing the new node into the Queue whose address is stored in ptr into the Queue
	*/
    queue.add(ptr);

    /*
	This is a check to see if the Queue is empty or not using empty function.
	*/
    cout << "This is a check to see if the Queue is empty or not using empty function." << endl;
    if (queue.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not Empty." << endl
             << endl;
    }

    /*
	Now printing the data present in the Queue
	*/
    cout << "Printing the data present in the Queue using print function." << endl;
    queue.print();

    /*
	Deleting the latest node from the Queue using remove function when only one node is present in the Queue
	*/
    queue.remove();
    /*
	After Deleting first latest node from Queue, printing the Queue
	*/
    cout << "After Deleting latest node from Queue, printing all the data in the Queue." << endl;
    queue.print();

    /*
	Now iniializing a node and setting data using setData fuction.
	*/
    cNode *newNode = new cNode();
    newNode->setData(431);
    queue.add(newNode);
    cout << "\nNow iniializing a node and setting data using setData function. " << endl;
    queue.print();
    /*
	Now declaring few more nodes and setting data using set Data function and pushing them to queue
	*/

    cNode *node2 = new cNode();
    node2->setData(324);
    queue.add(node2);

    cNode *node3 = new cNode();
    node3->setData(235);
    queue.add(node3);

    cNode *node4 = new cNode();
    node4->setData(833);
    queue.add(node4);

    cNode *node5 = new cNode();
    node5->setData(424);
    queue.add(node5);

    cNode *node6 = new cNode();
    node6->setData(145);
    queue.add(node6);

    cNode *node7 = new cNode();
    node7->setData(524);
    queue.add(node7);

    /*
	Now Queue will be returned if isNotEmpty function returns true.
	*/
    cout << "\n\nNow Queue will be printed if isNotEmpty function returns true." << endl;
    if (queue.isNotEmpty())
        queue.print();
}
