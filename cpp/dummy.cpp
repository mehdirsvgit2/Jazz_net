#include <iostream>
#include "dummy.h"


using namespace std;

int Dummy::count = 0;

Dummy::Dummy()
{
	count ++;
}
Dummy::~Dummy()
{
	count --;
}

int Dummy::nobjs()
{ 
	return count; 
}
