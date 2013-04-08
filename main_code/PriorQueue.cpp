#include <stdlib.h>
#include <iostream>
#include "PriorQueue.h"
#include <assert.h>

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

bool QueuePriority::IsEmpty() const
{
	return QueueLength == 0;
}

int QueuePriority::Getlength() const
{
	return QueueLength;
}

void QueuePriority::Add(int c, int p)
{
	Wait = (int*)realloc(Wait, (QueueLength + 1) * sizeof(int));
	assert(Wait);
	Pri = (int*)realloc(Pri, (QueueLength + 1) * sizeof(int));
	assert(Pri);
	Wait[QueueLength] = c;
	Pri[QueueLength] = p;
	QueueLength++;
}

int QueuePriority::Extract()
{
	//if the queue is empty, there is nothing to extract, return -1
	if (!IsEmpty())
	{
		//suppose that the element with max priority is first
		int max_pri = Pri[0];
		int pos_max_pri = 0;
		for (int i = 1; i < QueueLength; i++)
		{
			if (max_pri < Pri[i])
			{
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		}
		//protect element with max priority from removal
		int ret_val = Wait[pos_max_pri];
		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;
		return ret_val;
	}
	else 
	{
		std::cout<<"Warning: you tried to get element from empty queue\n";
	}
	return 0;
}

std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP)
{
	cout_<<"|QueuePriority:\n";
	for (int i = 0; i < QP.QueueLength; i++)
	{
		cout_<<"|value = "<<QP.Wait[i]<<" priority = "<<QP.Pri[i]<<"\n";
	}
	cout_<<"\n";
	return cout_;
}
