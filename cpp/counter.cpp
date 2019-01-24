#include <iostream>
#include "counter.h"


using namespace std;

int Counter::count = 0;

Counter::Counter()
{
	count ++;
}
Counter::~Counter()
{
	count --;
}

int Counter::nobjs()
{ 
	return count; 
}
