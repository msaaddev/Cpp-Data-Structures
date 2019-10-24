#include <iostream>
#include "Queue.cpp"
using namespace std;

class cPriorityQue : public cQue
{
public:
    cPriorityQue(cNode *&ptr) : cQue(ptr) {}

    cPriorityQue() {}

    cPriorityQue(const cPriorityQue &src) : cQue((cQue &)src){};

    cPriorityQue &add(cNode *&ptr)
    {
        if (!top)
        {
            top = tail = ptr;
            tail->next = ptr = NULL;
        }
        else if (top->getPriority() < ptr->getPriority())
        {
            cStack::push(ptr);
        }

        else if (tail->getPriority() >= ptr->getPriority())
        {
            cQue::add(ptr);
        }

        else
        {
            cNode *rptr = top;
            while (rptr->getPriority() > ptr->getPriority())
            {
                rptr = rptr->next;
            }

            ptr->next = rptr->next;
            rptr->next = ptr;
            ptr = NULL;
        }
        return *this;
    }

    cNode *remove()
    {
        return cQue::remove();
    }

    void print()
    {
        cQue::print();
    }

    ~cPriorityQue()
    {
        cNode *ptr = top;

        tail = NULL; // Tail is going to NULL and we can make remaining code.

        while (ptr)
        {
            ptr = ptr->next;
            delete top;
            top = ptr; // In last loop Top will become Null.
        }
    }
};
