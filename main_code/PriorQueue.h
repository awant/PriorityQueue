#ifndef PRIORQUEUE_H
#define PRIORQUEUE_H
#include <stdlib.h>
#include <iostream>

class QueuePriority
{
	private:

	//pointer to array of elements
	int* Wait;

	//pointer to array of priority of elements
	int* Pri;

	//current length of the queue
	int QueueLength;

public:
	QueuePriority();
	~QueuePriority();

	//add element "ñ" with priority "p"
	void Add(int c, int p);

	//extract the element with the highest priority
	int Extract();

	//clear the queue, (QueueLength == 0)
	void Clear();

	//check for empty queue. Used in Extract()
	bool IsEmpty() const;

	//return the length of the queue
	int Getlength() const;

	//overload operator "<<" to display the priority queue
	friend
	std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP);
 };
#endif	//PriorQueue_H
