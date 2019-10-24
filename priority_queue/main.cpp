#include <iostream>
#include "priorityQue.cpp"
using namespace std;

int main()
{
    cPriorityQue queue;
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
    cout << endl
         << "This is a check to see if the Queue isNotEmpty by using isEmpty function." << endl;
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
    cNode *ptr = new cNode(132);
    ptr->setPriority(2);

    /*
	Pushing the new node whose address is stored in ptr into the Queue
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
	Deleting the latest node from the Queue using pop function when only one node is present in the Queue
	*/
    queue.remove();
    /*
	After Deleting first latest node from Queue, printing the Queue
	*/
    cout << "\n\nAfter Deleting latest node from Queue, printing all the data in the Queue." << endl;
    queue.print();

    /*
	Now iniializing a node and setting data using setData fuction.
	*/
    cNode *newNode = new cNode();
    newNode->setData(34);
    newNode->setPriority(31);
    queue.add(newNode);
    cout << "\nNow iniializing a node and setting data using setData fuction." << endl;
    queue.print();

    /*
	Now declaring few more nodes and setting data using set Data function and pushing them to queue
	*/
    cNode *node2 = new cNode();
    node2->setData(344);
    node2->setPriority(21);
    queue.add(node2);

    cNode *node3 = new cNode();
    node3->setData(131);
    node3->setPriority(23);
    queue.add(node3);

    cNode *node4 = new cNode();
    node4->setData(524);
    node4->setPriority(5);
    queue.add(node4);

    cNode *node5 = new cNode();
    node5->setData(424);
    node5->setPriority(4);
    queue.add(node5);

    cNode *node6 = new cNode();
    node6->setData(221);
    node6->setPriority(13);
    queue.add(node6);

    cNode *node7 = new cNode();
    node7->setData(513);
    node7->setPriority(3);
    queue.add(node7);

    cNode *node9 = new cNode();
    node9->setData(11);
    node9->setPriority(6);
    queue.add(node9);

    cNode *node10 = new cNode();
    node10->setData(51);
    node10->setPriority(8);
    queue.add(node10);

    cNode *node11 = new cNode();
    node11->setData(4915);
    node11->setPriority(11);
    queue.add(node11);

    cNode *node12 = new cNode();
    node12->setData(1953);
    node12->setPriority(14);
    queue.add(node12);

    /*
	Now printing Queue after pushing 7 new nodes
	*/
    cout << "\n\nNow printing Queue after pushing 7 new nodes if isNotEmpty function returns true\n";
    if (queue.isNotEmpty())
        queue.print();/*
	Now deleting top of queue when more then one nodes is present
	*/
	cout << "\n\nNow deleting top of Queue when more then one nodes is present\n";
	queue.remove();
	if (queue.isNotEmpty())
		queue.print();

	/*
	Now getting value of a node using getValue function
	*/
	cNode *node8 = new cNode();
	node8->setData(800);
	node8->setPriority(5);
    cout << "\n\nNow getting value of a node8 using getData function: ";
    cout << node8->getData() << "\n";

    /*
	Now deleting top of queue when more then one nodes is present
	*/
    cout << "\n\nNow deleting top of Queue when more then one nodes is present\n";
    queue.remove();
    if (queue.isNotEmpty())
        queue.print();

    /*
	Copying content of one queue to another queue using copy constructor
	*/
    cPriorityQue newQueue(queue);
    /*
	/*
	Copying content of one queue to another queue using copy constructor
	*/
    cout << "\n\nCopying content of one queue to another queue using copy constructor and printing the contents of queue destination." << endl;
    newQueue.print();
}
