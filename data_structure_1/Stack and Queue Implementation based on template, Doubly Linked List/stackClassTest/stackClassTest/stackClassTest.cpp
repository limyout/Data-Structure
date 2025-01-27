#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "genericStackDL.h"

using namespace std;

template<typename T>
stackClass<T>::stackClass() {
	Top = NULL;
	Count = 0;;
}

template<typename T>
stackClass<T>::stackClass(const stackClass<T>& S)
{
	Top = S.Top;
}

template<typename T>
stackClass<T>::~stackClass()
{
	int Temp;
	while (!IsEmpty()) {
		Temp = Pop();
	}

}

template<typename T>
void stackClass<T>::Push(T Item)
{
	node<T> *NewTop = new node<T>;
	NewTop->Data = Item;
	Count += 1;

	if (Count == 0) {
		Head = NewTop;
	}
	else if (Count > 0 && Count < 101) {

		Temp = Head;
		for (int i = 0; i < Count - 1; i++) {
			Temp = Temp->Next;
		}
		NewTop->Prev = Temp;
		Temp->Next = NewTop;
	}
	else {
		cout << "Addition on Full Stack" << endl << endl;
		Pop();
	}
	Top = NewTop;
}
template<typename T>
int stackClass<T>::Pop()
{
	if (IsEmpty()) {
		cout << "Deletion on Empty Stack" << endl << endl;
	}
	else {
		Temp = Head;
		for (int i = 0; i < Count - 1; i++) {
			Temp = Temp->Next;
		}
		Top = Temp->Prev;
		delete Temp;
	}
	Count -= 1;
	return 0;
}

template<typename T>
void stackClass<T>::GetTop(T& Item)
{
	Temp = Head;
	for (int i = 0; i < Count - 1; i++) {
		Temp = Temp->Next;
	}
	Item = Temp->Data;
	cout << "Top's Data : " << Count << " ----- " << Item << endl;
}

template<typename T>
bool stackClass<T>::IsEmpty()
{
	if (Count != 0) {
		return 0;
	}
}

template<typename T>
bool stackClass<T>::IsFull()
{
	if (Count == 100) {
		return 1;
	}
}

template<typename T>
void  stackClass<T>::PrintList() {
	Temp = Head;
	for (int i = 1; i < Count + 1; i++) {
		cout << i << "'s list : " << Temp->Data << "   " << endl;
		Temp = Temp->Next;
	}
	cout << endl;
}


int main()
{
	stackClass<string> str_list;
	stackClass<int> int_list;
	stackClass<double> double_list;
	int item = 0;


	str_list.Pop(); // Error 'Stack Underflow'

	for (int i = 0; i < MAX + 1; i++) {
		str_list.Push("aaa");
	}
	str_list.PrintList();

	str_list.Push("aaa"); // Error 'Stack Overflow'

	str_list.PrintList();



	int_list.Pop(); // Error 'Stack Underflow'

	for (int i = 0; i < MAX + 1; i++) {
		int_list.Push(i + 1);
	}
	int_list.PrintList();

	int_list.Push(101); // Error 'Stack Overflow'

	int_list.PrintList();

	int_list.Pop();

	int_list.PrintList();  // Showing the stack



	double_list.Pop(); // Error 'Stack Underflow'

	for (double i = 0.5; i < MAX + 1; i++) {
		double_list.Push(i + 1);
	}
	double_list.PrintList();

	double_list.Push(100.5);

	double_list.PrintList(); // Error 'Stack Overflow'
}