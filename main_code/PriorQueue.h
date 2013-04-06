#include <stdlib.h>
#include <iostream>

 class QueuePriority
 {
 private:
   int* Wait;			//указатель на массив элементов
   int* Pri;			//указатель на массив приоритетов элементов соответственно
   int QueueLength;		//текущая длина очереди
 public:
   QueuePriority();
   ~QueuePriority();
   void Add(int c,int p);	//добавление элемента "с" с приоритетом "p"
   int Extract();			//извлечение элемента с наибольшим приоритетом
   void Clear();			//очистка очереди, (QueueLength == 0)
   bool IsEmpty() const;	//проверка на пустоту очереди. Используется в Extract(), ведь из пустой очереди мы не можем ничего извлечь.
   int Getlength() const;	//возвращает длину очереди
   friend std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP);	//перегрузка оператора "<<" для вывода на экран очереди с приоритетом
 };