#pragma once
#include <Windows.h>

/*
windows �µĻ������������࣬�����������ȷֲ�
Method: Getrandom rng;
        rng.get(); //����unsigned long long��Χ�ڵ������
        rng.getint(int left = 0, int right = 100); //���[left, right) ��Χ�ڵ����������
                                                   //����long long��Χ��ԭ�򣬿��ܲ��Ǿ��ȷֲ�
                                                   //��right - left �Ƚ�Сʱ����Ϊ�Ǿ��ȷֲ�
        rng.getdouble(double left = 0.0, double right = 1.0); // ���[left, right]��Χ�ڵ����ʵ��
                                                              //[left, right]��Χ����̫��
*/
class Getrandom
{
public:
  Getrandom();
  ~Getrandom();

  // ���unsigned long long ��Χ�ڵľ��ȷֲ������
  unsigned long long get(); 

  //���[left, right���ڵ��������
  long long getint(long long left = 0, long long right = 100);

  //���[left, right) �ڵľ��ȷֲ����ʵ��
  double getdouble(double left = 0.0, double right = 1.0);
private:
  HCRYPTPROV Rnd;
  bool available;
};
