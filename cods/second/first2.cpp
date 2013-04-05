#include <stdlib.h>
#include <iostream>
#include "First2.h"

QueuePriority::~QueuePriority()
{
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority()
{
	QueueLength = 0;
	Wait = (int*)calloc(QueueLength, sizeof(int));
	Pri = (int*)calloc(QueueLength, sizeof(int));
}

void QueuePriority::Clear()
{
	delete[]Wait;
	delete[]Pri;
	QueueLength = 0;
	Wait = (int*)calloc(QueueLength, sizeof(int));
	Pri = (int*)calloc(QueueLength, sizeof(int));
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
	Pri = (int*)realloc(Pri, (QueueLength + 1) * sizeof(int));
	Wait[QueueLength] = c;
	Pri[QueueLength] = p;
	QueueLength++;
}

int QueuePriority::Del()
{
	if (!IsEmpty())
	{
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
		int ret_val = Wait[pos_max_pri];
		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;
		return ret_val;
	}
	else return -1;
}

std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP)
{
	std::cout<<"This is dump of QueuePriority:\n";
	for (int i = 0; i < QP.QueueLength; i++)
	{
		std::cout<<"value = "<<QP.Wait[i]<<" priority = "<<QP.Pri[i]<<"\n";
	}
	std::cout<<"\n";
	return cout_;
}