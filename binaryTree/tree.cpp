#include <iostream>
#include "node.cpp"
using namespace std;

class cBinTree
{
    cNode *root;
    int count;

public:
    cBinTree() : root(NULL), count(0) {}
    cBinTree(cNode *&ptr) : root(ptr), count(1)
    {
        ptr = root->leftNode = root->rightNode = NULL;
    }

    bool isEmpty();
    bool isNotEmpty();
    void insert(cNode *&ptr);
    void printPreOrder();
    void printPostOrder();
};

bool cBinTree::isEmpty()
{
    if (!root)
        return true;
    else
        return false;
}

bool cBinTree::isNotEmpty()
{
    if (!root)
        return false;
    else
        return true;
}

void cBinTree::insert(cNode *&ptr)
{
    if (!root)
        root = ptr;
    else
    {
        cNode *rptr, *bptr;
        rptr = root;
        while (rptr)
        {
            bptr = rptr;
            if (rptr->getData() < ptr->getData())
                rptr = rptr->rightNode;
            else
                rptr = rptr->leftNode;
        }

        if (bptr->getData() < ptr->getData())
            bptr->rightNode = ptr;
        else
            bptr->leftNode = ptr;

        ++count;
    }

    ptr = ptr->leftNode = ptr->rightNode = NULL;
}

void cBinTree::printPreOrder()
{
    void prtPreOrder(cNode * root);

    if (!root)
        cout << "\nEmpty Tree\n";
    else
        prtPreOrder(root);
}

void prtPreOrder(cNode *root)
{
    if (root)
    {
        root->print();
        prtPreOrder(root->leftNode);
        prtPreOrder(root->rightNode);
    }
}

void cBinTree::printPostOrder()
{
    void prtPostOrder(cNode * root);

    if (!root)
        cout << "\nEmpty Tree\n";
    else
        prtPostOrder(root);
}

void prtPostOrder(cNode *root)
{
    if (root)
    {
        prtPostOrder(root->leftNode);
        prtPostOrder(root->rightNode);
        root->print();
    }
}

}
