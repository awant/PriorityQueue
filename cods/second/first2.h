#include <stdlib.h>
#include <iostream>

 class QueuePriority
 {
 private:
   int* Wait;
   int* Pri;
   int QueueLength;
 public:
   QueuePriority();
   ~QueuePriority();
   void Add(int c,int p);
   int Del();
   void Clear();
   bool IsEmpty() const;
   int Getlength() const;
   friend std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP);
 };