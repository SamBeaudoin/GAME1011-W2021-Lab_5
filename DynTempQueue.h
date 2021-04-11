#include <cstddef>
#include <iostream>
#ifndef DYN_TEMP_QUE
#define DYN_TEMP_QUE

using namespace std;

template <class T>
class DynTempQueue
{
private:
	class QueueNode
	{
		friend class DynTempQueue;
		T value;
		QueueNode* next;
		QueueNode(T value1, QueueNode* next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	// These track the front and rear of the queue
	QueueNode* front;
	QueueNode* rear;
public:
	// Constructor and Destructor
	DynTempQueue();
	~DynTempQueue();

	// Member functions
	void enqueue(T object);
	void dequeue(T& object);
	bool isEmpty() const;
	void clear();
	void showValues();
};
#endif

template<class T>
inline DynTempQueue<T>::DynTempQueue()
{
	front = NULL;
	rear = NULL;
}

template<class T>
inline DynTempQueue<T>::~DynTempQueue()
{
	clear();
}

template<class T>
inline void DynTempQueue<T>::enqueue(T object)
{
	if (isEmpty())
	{
		front = new QueueNode(object);
		rear = front;

	}
	else
	{
		rear->next = new QueueNode(object);
		rear = rear->next;
	}
	showValues();
}

template<class T>
inline void DynTempQueue<T>::dequeue(T& object)
{
	QueueNode* temp;
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
		exit(1);
	}
	else
	{
		object = front->value;
		temp = front;
		front = front->next;
		delete temp;
		showValues();
	}
}

template<class T>
inline bool DynTempQueue<T>::isEmpty() const
{
	if (front == NULL)
		return true;
	else
		return false;
}

template<class T>
inline void DynTempQueue<T>::clear()
{
	int value;   // Dummy variable for dequeue

	while (!isEmpty())
		dequeue(value);
}

template<class T>
inline void DynTempQueue<T>::showValues()
{
	QueueNode* temp = front;
	std::cout << "The contents inside the queue are: ";
	while (temp != NULL)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}