#include <cstddef>
#include <iostream>

#ifndef DYN_TEMP_STACK
#define DYN_TEMP_STACK

using namespace std;

template <class T>
class DynTempStack
{
private:
    class StackNode
    {
        friend class DynTempStack;
        T value;
        StackNode* next;
        // Constructor
        StackNode(T value1, StackNode* next1 = NULL)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode* top;
public:
    DynTempStack() { top = NULL; }
    void push(T object);
    void pop(T& object);
    bool isEmpty() const;
    void showValues();
};
#endif

template<class T>
inline void DynTempStack<T>::push(T object)
{
    top = new StackNode(object, top);
    showValues();
}

template<class T>
inline void DynTempStack<T>::pop(T& object)
{
    StackNode* temp;

    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        exit(1);
    }
    else   // Pop value off top of stack
    {
        object = top->value;
        temp = top;
        top = top->next;
        delete temp;

    }
    showValues();
}

template<class T>
inline bool DynTempStack<T>::isEmpty() const
{
    if (!top)
        return true;
    else
        return false;
}

template<class T>
inline void DynTempStack<T>::showValues()
{
    StackNode* temp = top;
    std::cout << "The contents in the stack are: ";
    while (temp != NULL)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}