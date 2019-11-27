#include <iostream>
#include "node.cpp"
using namespace std;

class cList
{

    cNode *headNode;
    int count;

public:
    cList()
    {
        headNode = NULL;
        count = 0;
    }
    cList(cNode *&ptr) : headNode(ptr), count(1)
    {
        headNode->next = ptr = NULL;
    }

    bool isNotEmpty()
    {
        if (headNode)
            return false;
        else
            return true;
    }

    int getCount() const
    {
        return count;
    }

    cList &insert(cNode *&ptr)
    {
        if (headNode)
        {
            ptr->next = NULL;
            headNode = ptr;
        }
        else
        {
            headNode = ptr;
            ptr->next = NULL;
        }

        ptr = NULL;
        ++count;

        return *this;
    }

    cList &insertAt(int index, cNode *&ptr)
    {
        if (index <= 0)
        {
            insert(ptr);
            return *this;
        }
        if (index > count)
            index = count;

        cNode *rptr = headNode;

        for (int i = 1; i < index; ++i)
        {
            rptr = rptr->next;
        }

        ptr->next = rptr->next;
        rptr->next = ptr;
        ptr = NULL;
        ++count;

        return *this;
    }

    cNode *remove()
    {
        if (isNotEmpty())
        {
            cNode *ptr = headNode;
            headNode = headNode->next;
            ptr->next = NULL;
            --count;
            return ptr;
        }
    }

    cNode *removeAt(int index)
    {
        if (index <= 0)
            return remove();
        if (index >= count)
            index = count - 1;

        cNode *rptr = headNode;

        for (int i = 1; i < index; i++)
        {
            rptr = rptr->next;
        }

        cNode *ptr;
        ptr = rptr->next;
        rptr->next = ptr->next;
        --count;
        ptr->next = NULL;
        return ptr;
    }

    cNode operator[](int index)
    {
        if (index <= 0)
            return *headNode;
        if (index >= count)
        {
            index = count - 1;
            cNode *rptr = headNode;
            for (int i = 0; i < index; ++i)
            {
                rptr = rptr->next;
            }

            return *rptr;
        }


    }

    cList &swapNodesAt(int index1, int index2)
    {
        if (index1 < 0)
            index1 = 0;
        if (index2 < 0)
            index2 = 0;

        if (index1 >= count)
            index1 = count - 1;

        if (index2 = count)
            index2 = count - 1;

        if (index1 == index2)
            return *this;
        if (index1 < index2)
        {
            insertAt(index2 - 1, removeAt(index1));
            insertAt(index1, removeAt(index2));
        }
        else
        {
            insertAt(index1 - 1, removeAt(index2));
            insertAt(index2, removeAt(index1));
        }

        return *this;
    }

    cList &reverse()
    {
        if (count < 2)
            return *this;

        cNode *rptr, **arr = new cNode *[count];
        rptr = headNode;
        for (int i = 0; i < count; ++i)
        {
            arr[i] = rptr;
            rptr = rptr->next;
        }

        for (int i = 1; i < count; ++i)
        {
            arr[i]->next = arr[i - 1];
        }

        arr[0] = NULL;
        headNode = arr[count - 1];
        delete[] arr;
        return *this;
    }
};
