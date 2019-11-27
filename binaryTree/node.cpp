#include <iostream>
using namespace std;

class cNode
{
    int data;


public:
    cNode *leftNode, *rightNode;

    cNode() {}
    cNode(int d) : data(d) {}
    int getData() const;
    cNode &setData(int data);
    void print() const;
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

/*
Default desstructor wouldn't delete the memory allocated on HEAP
*/
cNode::~cNode()
{
}