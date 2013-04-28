#include <iostream>

#include <assert.h>
#include <stdlib.h>

#include "Prior_Queue.h"

QueuePriority::~QueuePriority()
{
  delete[]Wait;
  delete[]Pri;
}

QueuePriority::QueuePriority()
{
  QueueLength = 0;
  Wait = (int*)calloc(QueueLength, sizeof(int));
  assert(Wait);
  Pri = (int*)calloc(QueueLength, sizeof(int));
  assert(Pri);
}

void QueuePriority::Clear()
{
  delete[]Wait;
  delete[]Pri;
  QueueLength = 0;
  Wait = (int*)calloc(QueueLength, sizeof(int));
  assert(Wait);
  Pri = (int*)calloc(QueueLength, sizeof(int));
  assert(Pri);
}

int QueuePriority::IsEmpty() const
{
  return QueueLength == 0;
}

int QueuePriority::Getlength() const
{
  return QueueLength;
}

void QueuePriority::Add(int elem, int key)
{
  int i = 0;
  int elem_cur = 0, key_cur = 0;
  Wait = (int*)realloc(Wait, (QueueLength + 1) * sizeof(int));
  assert(Wait);
  Pri = (int*)realloc(Pri, (QueueLength + 1) * sizeof(int));
  assert(Pri);
  Wait[QueueLength] = elem;
  Pri[QueueLength] = key;
  QueueLength++;
  i = QueueLength - 1;
  // Element with a higher priority "pops up":
  while ((i > 0) && (Pri[(i - 1) / 2] < Pri[i]))
  {
    elem_cur = Wait[(i - 1) / 2];
    key_cur = Pri[(i - 1) / 2];
    Wait[(i - 1) / 2] = Wait[i];
    Pri[(i - 1) / 2] = Pri[i];
    Wait[i] = elem_cur;
    Pri[i] = key_cur;
    i = ((i - 1) / 2);
  }
}

int QueuePriority::Extract()
{
  if (!QueueLength)
  {
    std::cout << "Queue is empty" << std::endl;
    return -1;
  }
  if (QueueLength == 1)
  {
    QueueLength = 0;
    return Wait[0];
  }
  int ret_elem = Wait[0];
  Wait[0] = Wait[QueueLength - 1];
  Pri[0] = Pri[QueueLength - 1];
  QueueLength--;
  Recovery(0);
  return (ret_elem);
}

void QueuePriority::Recovery(int i)
{
  assert(i >= 0);
  int right = (2 * i + 2);
  int left = (2 * i + 1);
  int largest = i;
  int elem_cur = 0, prior_cur = 0;
  if ((left < QueueLength) && (Pri[left] > Pri[i]))
    largest = left;
  if ((right < QueueLength) && (Pri[right] > Pri[largest]))
    largest = right;
  if (largest != i)
  {
    elem_cur = Wait[i];
    prior_cur = Pri[i];
    Wait[i] = Wait[largest];
    Pri[i] = Pri[largest];
    Wait[largest] = elem_cur;
    Pri[largest] = prior_cur;
    QueuePriority::Recovery(largest);
  }
}

void QueuePriority::Dump() const
{
  std::cout << "Queue Priority:" << std::endl;;
  for (int i = 0; i < QueueLength; i++)
    {
      std::cout << "elem[" << i << "] = " << Wait[i]
		<< " prior[" << i << "] = " << Pri[i]
		<< std::endl;
    }
}

std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP)
{
  cout_<<"|QueuePriority: (by levels)" << std::endl;
  for (int i = 0; i < QP.QueueLength; i++)
  {
    cout_ << "|value = " << QP.Wait[i] << " priority = " << QP.Pri[i] << std::endl;
  }
  cout_ << std::endl;
  return cout_;
}
