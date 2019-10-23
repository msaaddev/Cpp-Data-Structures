#include <iostream>
using namespace std;

class cNode
{
    int data;

public:
    cNode *next;

    cNode() {}
    cNode(int d) : data(d) {}
    int getData() const;
    cNode *setData(int data);
    void print() const;
};

int cNode::getData() const
{
    return data;
}

void cNode::print() const
{
    cout << data << " ";
}
