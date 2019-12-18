#include <iostream>
using namespace std;

class cNode
{
    int data;
    int priority;

public:
    cNode *right, *left;

    cNode() {}
    cNode(int d) : data(d) {}
    int getData() const;
    cNode &setData(int data);
    void print() const;
    void setPriority(int prior);
    int getPriority();
    void printPriority() const;
    ~cNode();
};

int cNode::getData() const
{
    return data;
}

void cNode::print() const
{
    cout << data << " ";
}

cNode &cNode::setData(int number)
{
    data = number;
    return *this;
}

void cNode::setPriority(int prior)
{
    priority = prior;
}

/*
Getting the priority of data
*/
int cNode::getPriority()
{
    return priority;
}

/*
Function to print priority of data
*/
void cNode::printPriority() const
{
    cout << priority << " ";
}

/*
Default desstructor wouldn't delete the memory allocated on HEAP
*/
cNode::~cNode()
{
}