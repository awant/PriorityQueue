#ifndef PRIOR_QUEUE_H
#define PRIOR_QUEUE_H
#include <iostream>

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
  
  // Add element in queue with priority (key)
  void Add(int elem, int key);
  
  // Extract element with highest priority
  int Extract();
  
  // Recovery properties of binary heap (if there has been only one change!)
  void Recovery(int i);
  
  // Clear the queue, (QueueLength == 0)
  void Clear();

  // Check for empty queue
  int IsEmpty() const;

  // Return the length of the queue
  int Getlength() const;
  
  // Print queue with priority in the form of a binary tree - line by line
  void Dump() const;
  
  // Overload operator "<<" to display the priority queue
  friend
  std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP);
  
 };
 
#endif	// PRIOR_QUEUE_H
