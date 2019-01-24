#include<iostream>
#include "dummy.h"
using namespace std;

int main(void)
{
  Dummy *obj1 = new Dummy();
  Dummy *obj2 = new Dummy();
  delete obj2;
  cout << "Number of instances is : " << Dummy::nobjs();

  return 0;
}