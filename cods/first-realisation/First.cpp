#include <iostream>

class QueuePriority
{
private:
	int* Wait;
	int* Pri;
	int MaxQueueLength;
	int QueueLength;
public:
	QueuePriority(int m);
	~QueuePriority();
	void Add(int c, int p);
	int Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();
};

void QueuePriority::Show()
{
	std::cout<<"\n-----------------------------\n";
	for (int i = 0; i<QueueLength; i++)
	{
		std::cout<<Wait[i]<<" - "<<Pri[i]<<"\n\n";
	}
	std::cout<<"\n-----------------------------\n";
}

QueuePriority::~QueuePriority()
{
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority(int m)
{
	MaxQueueLength = m;
	Wait = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	QueueLength = 0;
}

void QueuePriority::Clear()
{
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	return QueueLength;
}

void QueuePriority::Add(int c, int p)
{
	if (!IsFull())
	{
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

int QueuePriority::Extract()
{
	if (!IsEmpty())
	{
		int max_pri = Pri[0];
		int pos_max_pri = 0;

		for (int i = 1; i < QueueLength; i++)
		{
			if (max_pri<Pri[i])
			{
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		}

		int temp1 = Wait[pos_max_pri];

		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;
		return temp1;
	}
	else return -1;
}

int main()
{
	QueuePriority QP(25);
	for(int i=0;i<7;i++)
	{
		QP.Add(i, ((i+3)*7)%12-5);
	}
	QP.Show();
	QP.Extract();
	QP.Show();
	return (0);
}
