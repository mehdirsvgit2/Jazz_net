#include<iostream>
#include "counter.h"
using namespace std;

int main(void)
{
  Counter *obj1 = new Counter();
  Counter *obj2 = new Counter();
  delete obj2;
  cout << "Number of instances is : " << Counter::nobjs();

  return 0;
}
