// Check for exception element from an empty queue

#include "fstream"
#include <iostream>

#include "Prior_Queue.h"

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
    std::cout<<"failed" << std::endl;
    file << "test-2" << std::endl;
    file << "	check for exception element from an empty queue...failed" << std::endl;
  }
  else
  {
    std::cout<<"success" << std::endl;
    file << "test-2" << std::endl;
    file << "	check for exception element from an empty queue...ok" << std::endl;
  }
  file.close();
  return (0);
}
