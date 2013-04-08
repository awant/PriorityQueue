//check for exception element from an empty queue
#include <stdlib.h>
#include "iostream"
#include "PriorQueue.h"
#include <conio.h>

int main()
{
	int extr = 0;
	QueuePriority QP;
	QP.Add(31, 1);
	QP.Add(22, 8);
	std::cout<<QP;
	extr = QP.Extract();
	extr = QP.Extract();
	extr = QP.Extract();
	std::cout<<QP;
	printf("extract value = %d", extr);
	_getch();
	return (0);
}