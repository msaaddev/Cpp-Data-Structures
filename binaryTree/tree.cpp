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
    void printInfixOrder();
    cNode *search(cNode *&ptr);
    int getMaxDegree();
    ~cBinTree();
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

void cBinTree::printInfixOrder()
{
    void prtInfixOrder(cNode * root);

    if (!root)
        cout << "\nEmpty Tree\n";
    else
        prtInfixOrder(root);
}

void prtInfixOrder(cNode *root)
{
    if (root)
    {
        prtInfixOrder(root->leftNode);
        root->print();
        prtInfixOrder(root->rightNode);
    }
}

cBinTree::~cBinTree()
{
    void deleteNodes(cNode * root);
    if (root)
        deleteNodes(root);
}

void deleteNodes(cNode *root)
{
    if (root)
    {
        deleteNodes(root->leftNode);
        deleteNodes(root->rightNode);
        delete root;
    }
}

cNode *cBinTree::search(cNode *&ptr)
{
    if (isNotEmpty())
    {
        cNode *rptr = root;
        while (rptr)
        {
            if (rptr == ptr)
                return ptr;
            if (rptr->getData() < ptr->getData())
                rptr = rptr->rightNode;
            else
                rptr = rptr->leftNode;
        }
    }
    return NULL;
}

int cBinTree::getMaxDegree()
{
    void getDegree(cNode * root, int &degree);
    int degree = 1;
    getDegree(root, degree);
}

void getDegree(cNode *root, int &degree)
{
    if (root)
    {
        if (root->leftNode && root->rightNode)
            degree = 2;
        else
        {
            getDegree(root->leftNode, degree);
            getDegree(root->rightNode, degree);
        }
    }
}
