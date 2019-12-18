#include <iostream>
#include "node.cpp"
using namespace std;

class DList
{
private:
    cNode *leftHead, *rightHead;
    int count;

public:
    DList() : leftHead(NULL), rightHead(NULL), count(0) {}
    DList(cNode *&ptr) : leftHead(ptr), rightHead(ptr), count(1)
    {
        leftHead->right = rightHead->left = ptr = NULL;
    }

    DList(const DList &src) : leftHead(src.leftHead), rightHead(src.rightHead), count(src.count)
    {
        if (count)
        {
            cNode *sptr, *dptr;
            int i;

            leftHead = dptr = new cNode(*src.leftHead);
            sptr = src.leftHead->right;
            for (i = 1; i < count; ++i)
            {
                dptr->right = new cNode(*sptr);
                dptr->right->left = dptr;
                dptr = dptr->right;
                sptr = sptr->right;
            }
            rightHead = dptr;
        }
    }

    DList &insertRight(cNode *&ptr)
    {
        ptr->left = rightHead;
        rightHead->right = ptr;
        rightHead = ptr;
        rightHead->left = ptr = NULL;
        ++count;
        return *this;
    }

    DList &insertLeft(cNode *&ptr)
    {
        ptr->right = leftHead;
        leftHead->left = ptr;
        leftHead = ptr;
        leftHead->left = ptr = NULL;
        ++count;
        return *this;
    }

    DList &insertAt(int index, cNode *&ptr)
    {
        cNode *rptr, *dptr;
        if (index <= 0)
            return insertLeft(ptr);
        if (index >= count)
            return insertRight(ptr);
        if (index < count / 2)
        {
            rptr = leftHead;
            for (int i = 1; i <= index; ++i)
            {
                dptr = rptr;
                rptr = rptr->right;
            }
        }
        else
        {
            rptr = rightHead;
            for (int i = count; i > index; --i)
            {
                dptr = rptr;
                rptr = rptr->left;
            }
        }

        ptr->left = dptr;
        dptr->right = ptr;
        rptr->left = ptr;
        ptr->right = rptr;
        rptr = ptr = NULL;
    }

    cNode *removeLeft()
    {
        cNode *ptr = leftHead;
        leftHead = leftHead->right;
        ptr->right = NULL;
        ptr->left = NULL;
        --count;
        return ptr;
    }

    cNode *removeRight()
    {
        cNode *ptr = rightHead;
        rightHead = rightHead->left;
        ptr->right = NULL;
        ptr->left = NULL;
        --count;
        return ptr;
    }

    cNode *removeAt(int index)
    {
        if (index <= 0)
            return removeLeft();
        if (index >= count)
            return removeRight();

        cNode *rptr, *ptr;

        if (index < count / 2)
        {
            rptr = leftHead;
            for (int i = 0; i < index; i++)
                rptr = rptr->right;
            ptr = rptr->right;
            rptr->right = ptr->right;
            ptr->right->left = rptr;
        }
        else
        {
            rptr = rightHead;
            for (int i = count; i > index; --i)
                rptr = rptr->left;

            ptr = rptr->left;
            rptr->left = ptr->left;
            ptr->left->right = rptr;
        }

        ptr->right = ptr->left = NULL;
        return ptr;
    }

    /* void *&swap(cNode *p1, cNode *p2)
    {
        cNode *temp = p1;
        p1->left->right = p1->right;
        p1->right->left = p1->left;

        p1 = p1->right;

        cNode *temp2 = p2;
        p2->left->right = temp;
        temp->left = p2->left;

    } */

    ~DList()
    {
        for (int i = 0; i < count; i++)
        {
            rightHead = leftHead;
            leftHead = leftHead->right;
            delete rightHead;
        }
    }
};