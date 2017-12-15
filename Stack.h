#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
//#include "Object.h"

class Stack{

	public:

	virtual bool push(string*)=0;
	virtual string* pop()=0;
	virtual bool isEmpty()=0;


};

#endif
