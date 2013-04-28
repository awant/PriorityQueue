// check for correct extraction element

#include "fstream"
#include <iostream>

#include "Prior_Queue.h"

int main()
{
  // elem with max prior.
  int ewmp = 10;
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
    std::cout<<"failed" << std::endl;
    file << "test-1" << std::endl;
    file << "	check for correct extraction element...failed" << std::endl;
  }
  else
  {
    std::cout<<"success" << std::endl;
    file << "test-1" << std::endl;
    file << "	check for correct extraction element...ok" << std::endl;
  }
  file.close();
  return (0);
}
