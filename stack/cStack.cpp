#include <iostream>
#include "node.cpp"
using namespace std;

class cStack
{
    cNode *top;

public:
    cStack() : top(NULL){};
    cStack(cNode *ptr) : top(ptr)
    {
        top->next = NULL;
        ptr = NULL;
    };

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

    cStack *push(cNode *ptr)
    {
        ptr->next = top;
        top = ptr;
        ptr = NULL;
        return this;
    }

    cNode *pop()
    {
        cNode *ptr = top;
        top = top->next;
        ptr->next = NULL;
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
};
