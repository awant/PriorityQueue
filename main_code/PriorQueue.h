#include <iostream>
#ifndef PRIORQUEUE_H
#define PRIORQUEUE_H

class QueuePriority
{
	private:

	// Pointer to array of elements
	int* Wait;

	// Pointer to array of priority of elements
	int* Pri;

	// Current length of the queue
	int QueueLength;

public:
	QueuePriority();
	~QueuePriority();

	// Add element "c" with priority "p"
	void Add(int c, int p);

	// Extract the element with the highest priority
	int Extract();

	// Clear the queue, (QueueLength == 0)
	void Clear();

	// Check for empty queue. Used in Extract()
	bool IsEmpty() const;

	// Return the length of the queue
	int Getlength() const;

	// Overload operator "<<" to display the priority queue
	friend 
	std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP);
 };
#endif	// PriorQueue_H