#include <iostream>
#include "cStack.cpp"
using namespace std;

int main()
{
    cStack stack;
    //Checking if the stack is empty by using isNotEmpty function
    cout << "This is a check to see if the stack is empty by using isNotEmpty function. " << endl
         << endl;

    if (stack.isNotEmpty())
    {
        cout << "Stack is not empty." << endl;
    }
    else
    {
        cout << "Stack is Empty." << endl;
    }

    //Checking if the Stack is empty by using isEmpty function
    cout << "This is a check to see if the Stack is empty by using isEmpty function." << endl
         << endl;
    if (stack.isEmpty())
    {
        cout << "Stack is empty. " << endl;
    }
    else
    {
        cout << "Stack is not Empty." << endl
             << endl;
    }

    //Checking all the elements present in the stack by printing them
    cout << "This is a check to see all the elements present in the stack by printing them." << endl  << endl;

    stack.print();
    cout << endl;

    /*
	Declaring a node and setting the data
	*/
    cNode *ptr = new cNode(400);
    /*
	Now pushing the new node whose address is stored in ptr into the STACK
	*/
    stack.push(ptr);

    //Now checking that if Stack is empty or not using empty function
    cout << "This is a check to see if the Stack is empty or not using empty function." << endl << endl;

    if (stack.isEmpty())
    {
        cout << "Stack is empty." << endl
             << endl;
    }
    else
    {
        cout << "Stack is not Empty. " << endl;
    }

    /*
	Now printing the data present in the STACK
	*/
    cout << "Now printing the data present in the STACK using print function. " << endl;
    stack.print();

    /*
	Deleting the latest node from the STACK using pop function when only one node is present in the STACK
	*/
    stack.pop();

    /*
	After Deleting first latest node from STACK, printing the stack
	*/
    cout << endl << endl << "After Deleting first latest node from STACK, printing the stack. " << endl;
    stack.print();

    /*
	Now declaring a node and setting data using setData fuction
	*/
    cNode *newNode = new cNode();
    newNode->setData(133);
    stack.push(newNode);
    cout << endl << "Now declaring a node and setting data using setData fuction\n\n";
    stack.print();

    /*
	Now declaring few more nodes and setting data using set Data function and pushing them to
	*/
    cNode *node2 = new cNode();
    node2->setData(214);
    stack.push(node2);

    cNode *node3 = new cNode();
    node3->setData(351);
    stack.push(node3);

    cNode *node4 = new cNode();
    node4->setData(124);
    stack.push(node4);

    cNode *node5 = new cNode();
    node5->setData(513);
    stack.push(node5);

    cNode *node6 = new cNode();
    node6->setData(241);
    stack.push(node6);

    cNode *node7 = new cNode();
    node7->setData(631);
    stack.push(node7);

    //Now printing Stack after pushing 7 new nodes is isNotEmpty function returns true
    cout << endl
         << "Now Stack will be printed if isNotEmpty function returns true." << endl;
    if (stack.isNotEmpty())
        stack.print();
    /*
	Now deleting top of STACK when more then one nodes is present
    */

    cout << "\n\nNow deleting top of Stack when more then one nodes is present." << endl;
    stack.pop();
    if (stack.isNotEmpty())
        stack.print();

    /*
	Now getting value of a node using getValue function
	*/
    cNode *node8 = new cNode();
    node8->setData(1050);
    cout << "\n\nNow getting value of the node8 using getData function: ";
    cout << node8->getData() << "\n";
}