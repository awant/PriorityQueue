// Add many elements

#include "fstream"
#include <iostream>

#include "Prior_Queue.h"

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
    std::cout<<"failed" << std::endl;
    file << "test-3" << std::endl;
    file << "	add many elements...failed" << std::endl;
  }
  else
  {
    std::cout<<"success" << std::endl;
    file << "test-3" << std::endl;
    file << "	add many elements...ok" << std::endl;
  }
  file.close();
  return (0);
}
