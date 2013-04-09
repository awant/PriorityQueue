//add many elements
#include <stdlib.h>
#include "iostream"
#include "PriorQueue.h"
#define N 2999

int main()
{
	QueuePriority QP;
	for (int i = 1; i <= N; i++)
	{
		QP.Add(i, N - i);
	}
	std::cout<<QP;
	printf("extract value = %d", QP.Extract());
	return (0);
}
