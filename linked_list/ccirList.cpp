#include <iostream>
#include "node.cpp"
using namespace std;

class ccirList
{
    cNode *headNode;
    int count;

public:
    ccirList() : headNode(NULL), count(0) {}
    ccirList(cNode *ptr) : headNode(ptr), count(1)
    {
        headNode = headNode->next;
        ptr = NULL;
    }

    cNode *remove()
    {
        cNode *ptr = headNode->next;
        if (count > 1)
            headNode->next = ptr->next;
        else
            headNode = NULL;
        --count;
        return ptr;
    }

    cNode *removeAt(int index)
    {
        if (index <= 0 || count == 1)
            return remove();

        if (index >= count)
            index = count - 1;
        cNode *ptr, *rptr = headNode->next;

        if (index == count - 1)
            headNode = rptr;

        for (int i = 1; i < index; ++i)
        {
            rptr = rptr->next;
        }

        ptr = rptr->next;
        rptr->next = ptr->next;
        ptr->next = NULL;
        --count;
        return ptr;
    }

    ccirList &insert(cNode *&ptr)
    {
        if (headNode)
        {
            headNode = ptr;
            headNode->next = headNode;
            ++count;
            ptr = NULL;
        }
        else
        {
            ptr->next = headNode->next;
            headNode->next = ptr;
            ptr = NULL;
            ++count;
        }

        return *this;
    }

    ccirList insertAt(int index, cNode *&ptr)
    {
        if (!headNode)
            return insert(ptr);
        else
        {
            if (index < 0)
                index = 0;
            else if (index >= 0)
            {
                index = count;
            }
            cNode *rptr = headNode;
            for (int i = 1; i < index; ++i)
            {
                rptr = rptr->next;
            }

            ptr->next = rptr->next;
            rptr->next = ptr;
            if (index == count)
                headNode = ptr;
            ptr = NULL;
            ++count;

            return *this;
        }
    }
};