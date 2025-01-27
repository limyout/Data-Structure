#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "genericQueueDL.h"

using namespace std;

template<typename T>
queueClass<T>::queueClass() {
	Rear = NULL;
	Count = 0;;
}

template<typename T>
queueClass<T>::queueClass(const queueClass<T>& Q)
{
	Rear = Q.Rear;
}

template<typename T>
queueClass<T>::~queueClass()
{
	int Temp;
	while (!IsEmpty()) {
		Remove();
	}
}

template<typename T>
void queueClass<T>::Add(T Item)
{
	node<T> *NewRear = new node<T>;
	NewRear->Data = Item;
	
	if (Count == 0) {
			Head = NewRear;
			Rear = NewRear;
			Count += 1;
		}
	else if (Count > 0 && Count < 100) {
		Temp = Head;
		for (int i = 0; i < Count - 1; i++) {
			Temp = Temp->Next;
		}
		NewRear->Prev = Temp;
		Temp->Next = NewRear;
		Rear = NewRear;
		Count += 1;
	}
	else {
		cout << "Addition on Full queue" << endl << endl;
	}
}

template<typename T>
void queueClass<T>::Remove()
{
	if (IsEmpty()) {
		cout << "Deletion on Empty queue" << endl << endl;
	}
	else {
		Temp = Head;
		Head = Temp->Next;
		delete Temp;
		Count -= 1;
	}
}


template<typename T>
bool queueClass<T>::IsEmpty()
{
	if (Count != 0) {
		return 0;
	}
}


template<typename T>
bool queueClass<T>::IsFull()
{
	if (Count == MAX) {
		return 1;
	}
}

template<typename T>
void  queueClass<T>::PrintList() {
	Temp = Head;
	for (int i = 1; i < Count + 1; i++) {
		cout << i << "'s list : " << Temp->Data << "   " << endl;
		Temp = Temp->Next;
	}
	cout << endl;
}

int main()
{
	queueClass<string> str_list;
	queueClass<int> int_list;
	queueClass<double> double_list;
	int item = 0;


	str_list.Remove(); // Error 'Queue Underflow'

	for (int i = 0; i < MAX; i++) {
		str_list.Add("aaa");
	}
	str_list.PrintList();

	str_list.Add("aaa");

	str_list.PrintList(); // Error 'Queue Overflow'




	int_list.Remove(); // Error 'Queue Underflow'

	for (int i = 0; i < MAX; i++) {
		int_list.Add(i+1);
	}
	int_list.PrintList();

	int_list.Add(MAX + 1); // Error 'Queue Overflow'

	int_list.PrintList();

	int_list.Remove();

	int_list.PrintList(); // Showing the queue




	double_list.Remove(); // Error 'Queue Underflow'

	for (double i = 0.5; i < MAX; i++) {
		double_list.Add(i + 1);
	}
	double_list.PrintList();

	double_list.Add(MAX + 1);

	double_list.PrintList(); // Error 'Queue Overflow'
}