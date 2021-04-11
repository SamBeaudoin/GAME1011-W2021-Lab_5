#include "DynTempQueue.h"
#include "DynTempStack.h"
#include "ExampleClass.h"
#include<iostream>

using namespace std;

int main()
{
	system("Color F2");
	cout << "\n\n Preforming Templated actions...\n\n";
	system("pause");

	ExampleClass* Exe1 = new ExampleClass(2);
	ExampleClass* Exe2 = new ExampleClass(4);
	ExampleClass* Exe3 = new ExampleClass(6);
	ExampleClass* Exe4 = new ExampleClass(8);
	ExampleClass* Exe5 = new ExampleClass(10);
	ExampleClass* tempE = new ExampleClass(0);
	int temp = 0;

	DynTempStack<int>* DynTIntStack = new DynTempStack<int>();
	DynTempStack<ExampleClass>* DynTExampleStack = new DynTempStack<ExampleClass>();

	cout << "Pushing Ints...\n";

	DynTIntStack->push(1);
	DynTIntStack->push(3);
	DynTIntStack->push(5);
	DynTIntStack->push(7);
	DynTIntStack->push(9);

	cout << "Now Popping Ints...\n";

	DynTIntStack->pop(temp);
	DynTIntStack->pop(temp);
	DynTIntStack->pop(temp);
	DynTIntStack->pop(temp);
	DynTIntStack->pop(temp);

	cout << "Pushing Class Containing Int...\n";

	DynTExampleStack->push(*Exe1);
	DynTExampleStack->push(*Exe2);
	DynTExampleStack->push(*Exe3);
	DynTExampleStack->push(*Exe4);
	DynTExampleStack->push(*Exe5);

	cout << "Popping Class Containing Int...\n";
	
	DynTExampleStack->pop(*tempE);
	DynTExampleStack->pop(*tempE);
	DynTExampleStack->pop(*tempE);
	DynTExampleStack->pop(*tempE);
	DynTExampleStack->pop(*tempE);

	DynTempQueue<int>* DynTIntQue = new DynTempQueue<int>();
	DynTempQueue<ExampleClass>* DynTExampleQue = new DynTempQueue<ExampleClass>();

	cout << "Enqueing Ints...\n";

	DynTIntQue->enqueue(1);
	DynTIntQue->enqueue(3);
	DynTIntQue->enqueue(5);
	DynTIntQue->enqueue(7);
	DynTIntQue->enqueue(9);

	cout << "Dequeing Ints...\n";

	DynTIntQue->dequeue(temp);
	DynTIntQue->dequeue(temp);
	DynTIntQue->dequeue(temp);
	DynTIntQue->dequeue(temp);
	DynTIntQue->dequeue(temp);

	cout << "Enqueing Class's with an Int...\n";

	DynTExampleQue->enqueue(*Exe1);
	DynTExampleQue->enqueue(*Exe2);
	DynTExampleQue->enqueue(*Exe3);
	DynTExampleQue->enqueue(*Exe4);
	DynTExampleQue->enqueue(*Exe5);

	cout << "Dequeing Class's with an Int...\n";

	DynTExampleQue->dequeue(*tempE);
	DynTExampleQue->dequeue(*tempE);
	DynTExampleQue->dequeue(*tempE);
	DynTExampleQue->dequeue(*tempE);
	DynTExampleQue->dequeue(*tempE);

	return 0;
}