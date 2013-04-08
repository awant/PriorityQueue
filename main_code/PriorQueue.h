#include <stdlib.h>
#include <iostream>
#ifndef PRIORQUEUE_H
#define PRIORQUEUE_H

 class QueuePriority
 {
 private:
   int* Wait;			//��������� �� ������ ���������
   int* Pri;			//��������� �� ������ ����������� ��������� ��������������
   int QueueLength;		//������� ����� �������
 public:
   QueuePriority();
   ~QueuePriority();
   void Add(int c,int p);	//���������� �������� "�" � ����������� "p"
   int Extract();			//���������� �������� � ���������� �����������
   void Clear();			//������� �������, (QueueLength == 0)
   bool IsEmpty() const;	//�������� �� ������� �������. ������������ � Extract(), ���� �� ������ ������� �� �� ����� ������ �������.
   int Getlength() const;	//���������� ����� �������
   friend std::ostream& operator << (std::ostream& cout_, const QueuePriority& QP);	//���������� ��������� "<<" ��� ������ �� ����� ������� � �����������
 };

#endif 
