// Add many elements
#include "PriorQueue.h"
#include "fstream"
#include <iostream>
#define N 2999

int main()
{
	QueuePriority QP;
	std::ofstream file;
	file.open("log-file.txt", std::ios_base::app);
	if (file == NULL)
		return 0;
	int extr = N;
	for (int i = 1; i <= N; i++)
	{
		QP.Add(i, N - i);
	}
	for (int i = 1; (extr = QP.Extract()) && (i <= N + 3); i++)
	{
		if (extr == -1)
		{
			extr = i;
			break;
		}
	}
	if(extr == N)
	{
		std::cout<<"failed\n";
		file << "test-3\n";
		file << "	add many elements...failed\n";
	}
	else
	{
		std::cout<<"success\n";
		file << "test-3\n";
		file << "	add many elements...ok\n";
	}
	file.close();
	return (0);
}
