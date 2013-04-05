#include <stdlib.h>
#include <conio.h>
#include "First2.h"

int main()
{
	QueuePriority QP;
	QP.Add(31, 1);	
	QP.Add(65, 2);
	QP.Add(10, 10);
	QP.Add(54, 4);
	QP.Add(23, 5);
	QP.Add(72, 6);
	QP.Add(66, 7);
	QP.Add(22, 8);
	std::cout<<QP;
	QP.Del();
	std::cout<<QP;
	_getch();
	return (0);
}