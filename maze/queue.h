/* Templated queue class with enqueue,dequeue,isEmpty, and print member functions.*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <new>
#include <string>
using namespace std;

template<class T> class Queue;

template<class T>
class QueueNode
{
	friend class Queue<T>; //make Stack have access to Node data types
public:
    QueueNode(const T &); //copy constructor
	T getData() const;   //Access data//
private:
	T data; //data type
	QueueNode<T> *nextPtr; //self referential pointer to nect node
};

template<class T>
class Queue
{
public:
	Queue();
	~Queue();
	bool enqueue(const T &item); 
	T dequeue();
	bool isEmpty(void) const;
	void print(void) const;
private:
	QueueNode<T> *firstPtr;
	QueueNode<T> *lastPtr;
	QueueNode<T> *getNewNode(const T &);
};

template<typename T>
QueueNode<T>::QueueNode(const T &item)
{
	data=item;
	nextPtr=0;
}

template<typename T>
T QueueNode<T>::getData() const
{
	return data;
}

template<typename T>
QueueNode<T> *Queue<T>::getNewNode(const T &item)
{
	return new QueueNode<T>(item);
}

template<typename T>
Queue<T>::Queue()
: firstPtr(0), lastPtr(0)
{
}

template<typename T>
Queue<T>::~Queue()
{
	if(!isEmpty())
	{
		QueueNode<T> *currentPtr=firstPtr;
		QueueNode<T> *tempPtr;

		while(currentPtr!=NULL)
		{
			tempPtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
			delete tempPtr;
		}
	}
}

template<typename T>
bool Queue<T>::enqueue(const T &item)
{
	QueueNode<T> *newNode=getNewNode(item);
	bool correct=false;

	if(isEmpty())
	{
		firstPtr=newNode;
		lastPtr=newNode;
		correct=true;
	}
	else
	{
		lastPtr->nextPtr=newNode;
		lastPtr=newNode;
		correct=true;
	}

	return correct;
}

template<typename T>
T Queue<T>::dequeue()
{
	T item=firstPtr->getData();
	QueueNode<T> *tempPtr=firstPtr;

	if(!isEmpty())
	{
		firstPtr=firstPtr->nextPtr;
		delete tempPtr;
	}
	return item;
}


template<typename T>
bool Queue<T>::isEmpty(void) const
{
	if(firstPtr==NULL)
	{
		return true;
	}
	
	return false;
}

template<typename T>
void Queue<T>::print(void) const
{
	if(!isEmpty())
	{
		QueueNode<T> *currentPtr=firstPtr;
		int n=1;

	cout<<"Your queue is: ";
		while(currentPtr!=NULL)
		{
			cout<<currentPtr->getData();
			currentPtr=currentPtr->nextPtr;
			n++;
		}

	cout<<" "<<endl;
	}
	else
	{
		cout<<"Your queue is empty"<<endl;
	}
}

#endif