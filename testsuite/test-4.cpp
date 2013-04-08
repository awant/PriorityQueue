//negative elements with negative priority
#include <stdlib.h>
#include "iostream"
#include "PriorQueue.h"
#include <conio.h>
#define N 2999

int main()
{
	int extr = 0;
	QueuePriority QP;
	QP.Add(-2, 3);
	QP.Add(4, -7);
	QP.Add(-1, 1);
	QP.Add(3, -4);
	std::cout<<QP;
	extr = QP.Extract();
	printf("extract value = %d\n", extr);
	extr = QP.Extract();
	printf("extract value = %d\n", extr);
	extr = QP.Extract();
	printf("extract value = %d\n", extr);
	extr = QP.Extract();
	printf("extract value = %d\n", extr);
	std::cout<<QP;
	_getch();
	return (0);
}