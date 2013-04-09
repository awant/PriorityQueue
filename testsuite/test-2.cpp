// Check for exception element from an empty queue
#include "PriorQueue.h"
#include "fstream"
#include <iostream>

int main()
{
	std::ofstream file;
	file.open("log-file.txt", std::ios_base::app);
	if (file == NULL)
		return 0;
	int extr = -1;
	QueuePriority QP;
	QP.Add(31, 1);
	QP.Add(22, 8);
	extr = QP.Extract();
	extr = QP.Extract();
	extr = QP.Extract();
	if(extr != QP.Extract())
	{
		std::cout<<"failed\n";
		file << "test-2\n";
		file << "	check for exception element from an empty queue...failed\n";
	}
	else
	{
		std::cout<<"success\n";
		file << "test-2\n";
		file << "	check for exception element from an empty queue...ok\n";
	}
	file.close();
	return (0);
}