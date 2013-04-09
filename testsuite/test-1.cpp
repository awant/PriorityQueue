//check for correct extraction element
#include <stdlib.h>
#include "iostream"
#include "PriorQueue.h"

int main()
{
	int extr = 0;
	QueuePriority QP;
	QP.Add(31, 1);
	QP.Add(65, 2);
	QP.Add(10, 11);
	QP.Add(54, 4);
	QP.Add(23, 5);
	QP.Add(72, 6);
	QP.Add(66, 7);
	QP.Add(22, 8);
	std::cout<<QP;
	extr = QP.Extract();
	std::cout<<QP;
	printf("extract value = %d", extr);
	return (0);
}
