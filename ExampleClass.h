#pragma once
#ifndef EXAMPLE_CLASS
#define EXAMPLE_CLASS
#include <iostream>

using namespace std;
class ExampleClass
{
private:
public:
	int value;
	ExampleClass() { value = 0; };
	ExampleClass(int v) { value = v; };
	~ExampleClass() = default;
	ExampleClass& operator=(ExampleClass a)
	{
		this->value = a.value;
		return *this;
	}
};

ostream& operator<<(ostream& out, ExampleClass& exe)
{
	out << exe.value;
	return out;
}


#endif