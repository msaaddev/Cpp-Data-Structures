#include <iostream>
#include "cStack.cpp"
using namespace std;

class cQue : protected cStack
{
    cNode *tail;

public:
    cQue() : tail(NULL) {}

    cQue(cNode *&ptr) : cStack(ptr)
    {
        tail = top;
    }

    cQue(const cQue &src)
    {
        this->top = src.top;
        this->tail = src.tail;

        if (src.top)
        {
            cNode *sptr, *dptr;
            dptr = top = new cNode(*src.top);
            sptr = top->next;
            while (sptr)
            {
                dptr->next = new cNode(*sptr);
                dptr = dptr->next;
                sptr = sptr->next;
            }

            tail = dptr;
        }
    }

    bool isNotEmpty() const { return cStack::isNotEmpty(); }
    bool isEmpty() const { return cStack::isEmpty(); }

    cNode *remove()
    {
        return cStack::pop();
    }

    cQue &add(cNode *&ptr)
    {
        if (tail)
        {
            tail->next = ptr;
            tail = tail->next;
        }
        else
        {
            tail = top = ptr;
            cout << "hello ";
        }

        tail->next = NULL;
        ptr = NULL;
        return *this;
    }

    void print()
    {
        cStack::print();
    }

    cQue &operator=(const cStack &robj)
    {
        if (this == &robj)
            return *this;
        if (true)
        {
            cQue temp;
            temp.top = top;
            temp.tail = tail;
        }
    }
};