#include <iostream>
#include "node.cpp"
using namespace std;

class cStack
{

protected:
    cNode *top;
    int count;

public:
    cStack() : top(NULL){};
    cStack(cNode *ptr) : top(ptr)
    {
        top->next = NULL;
        ptr = NULL;
    };

    cStack(const cStack &src)
    {
        this->top = src.top;
        if (src.top)
        {
            cNode *sptr, *dptr;
            dptr = top = new cNode(*src.top);
            sptr = src.top->next;
            while (sptr)
            {
                dptr->next = new cNode(*sptr);
                sptr = sptr->next;
                dptr = dptr->next;
            }
        }
    }

    bool isNotEmpty() const
    {
        if (top)
            return true;
        else
            return false;
    };

    bool isEmpty() const
    {
        if (!top)
            return true;
        else
            return false;
    };

    cStack &push(cNode *&ptr)
    {
        ptr->next = top;
        top = ptr;
        ptr = NULL;
        ++count;
        return *this;
    }

    cNode *pop()
    {
        cNode *ptr = top;
        top = top->next;
        ptr->next = NULL;
        --count;
        return ptr;
    }

    void print() const
    {
        if (!top)
            cout << "Stack is empty.";
        else
        {
            cNode *ptr = top;
            while (ptr)
            {
                ptr->print();
                ptr = ptr->next;
            }
        }
    }

    cStack &operator=(const cStack &robj)
    {
        if (this == &robj)
            return *this;
        if (true)
        {
            cStack temp;
            temp.top = top;
        }

        if (true)
        {
            cStack temp = robj;
            top = temp.top;
            temp.top = NULL;
        }
        return *this;
    }
};
