// check for correct extraction element
#include "PriorQueue.h"
#include "fstream"
#include <iostream>

int main()
{
	int ewmp = 10; // elem with max prior.
	QueuePriority QP;
	std::ofstream file;
	file.open("log-file.txt", std::ios_base::app);
	if (file == NULL)
		return 0;
	QP.Add(31, 1);
	QP.Add(65, 2);
	QP.Add(10, 11);
	QP.Add(54, 4);
	QP.Add(23, 5);
	QP.Add(72, 6);
	QP.Add(66, 7);
	QP.Add(22, 8);
	if (ewmp != QP.Extract())
	{
		std::cout<<"failed\n";
		file << "test-1\n";
		file << "	check for correct extraction element...failed\n";
	}
	else
	{
		std::cout<<"success\n";
		file << "test-1\n";
		file << "	check for correct extraction element...ok\n";
	}
	file.close();
	return (0);
}
