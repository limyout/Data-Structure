#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "GenericDoublyListP.h"

using namespace std;

template<typename T>
listClass<T>::listClass() {
	Count = 0;
	Head = NULL;
	Temp = NULL;
}

template<typename T>
listClass<T>::listClass(const listClass<T>& L)
{
	Count = L.Count;
	if (L.Head == NULL)
		Head = NULL;
	else
	{
		Head->Data = L.Head->Data;
		node<T> *Temp1 = Head;
		Temp1->Next = NULL;
	}
}

template<typename T>
listClass<T>::~listClass()
{
	while (!IsEmpty()) {
		Delete(1);
	}

}

template<typename T>
void listClass<T>::Insert(int Position, T Item) {
	node<T> *n = new node<T>;
	n->Next = NULL;
	n->Data = Item;

	if (Head != NULL) {

		Temp = Head;

		if ((Count + 1) == Position) {
			for (int i = 1; i < (Position - 1); i++) {
				Temp = Temp->Next;
			}
			Temp->Next = n;
			n->Prev = Temp;
		}
		else {
			for (int i = 1; i < Position; i++) {
				Temp = Temp->Next;
			}
			n->Prev = Temp->Prev;
			Temp->Prev = n;
			n->Next = n->Prev->Next;
			n->Prev->Next = n;
		}
	}
	else {
		Head = n;
	}

	Count += 1;
}

template<typename T>
void listClass<T>::Delete(int Position) {

	node<T> *Temp = this->Head;

	if (IsEmpty())
		cout << "Deletion on Empty List" << endl;
	else if ((Position > Count) || (Position < 1))
		cout << "Position out of Range" << endl;
	else
	{
		Temp = Head;
		if (Position == 1) {
			Head = Head->Next;
		}
		else {
			for (int i = 1; i < Position; i++) {
				Temp = Temp->Next;
			}
			Temp->Next->Prev = Temp->Prev;
			Temp->Prev->Next = Temp->Next;
		}
		Count -= 1;
		delete (Temp);
	}
}

template<typename T>
void listClass<T>::Retrieve(int Position, T & item) {
	if (IsEmpty())
		cout << "Deletion on Empty List" << endl;
	else if ((Position > Count) || (Position < 1))
		cout << "Position out of Range" << endl;
	else
	{
		Temp = Head;
		for (int i = 1; i < Position; i++) {
			Temp = Temp->Next;
		}
		item = Temp->Data;
		cout << "copied value : " << item << endl;
	}
}

template<typename T>
bool listClass<T>::IsEmpty() {
	return (Count == 0);
}

template<typename T>
int listClass<T>::Length() {
	cout << "Length is " << Count << endl;
	return 0;
}

template<typename T>
void listClass<T>::PrintList() {
	Temp = Head;
	for (int i = 1; i < Count + 1; i++) {
		cout << i << "'s list : " << Temp->Data << "   ";
		Temp = Temp->Next;
	}
	cout << endl;
}

int main()
{
	listClass<string> str_list;
	listClass<int> int_list;
	listClass<double> double_list;

	string str_item;
	int int_item;
	double double_item;

	str_list.Insert(1, "가가");
	str_list.Insert(2, "나나");
	str_list.Insert(3, "다다");
	str_list.PrintList();
	str_list.Insert(3, "라라");
	str_list.PrintList();
	str_list.Insert(5, "마마");
	str_list.PrintList();
	str_list.Delete(4);
	str_list.PrintList();
	str_list.Delete(1);
	str_list.PrintList();
	str_list.Length();
	str_list.Retrieve(2, str_item);

	int_list.Insert(1, 1);
	int_list.Insert(2, 2);
	int_list.Insert(3, 3);
	int_list.PrintList();
	int_list.Insert(3, 4);
	int_list.PrintList();
	int_list.Insert(5, 5);
	int_list.PrintList();
	int_list.Delete(4);
	int_list.PrintList();
	int_list.Delete(1);
	int_list.PrintList();
	int_list.Length();
	int_list.Retrieve(2, int_item);

	double_list.Insert(1, 1.5);
	double_list.Insert(2, 2.5);
	double_list.Insert(3, 3.5);
	double_list.PrintList();
	double_list.Insert(3, 4.5);
	double_list.PrintList();
	double_list.Insert(5, 5.5);
	double_list.PrintList();
	double_list.Delete(4);
	double_list.PrintList();
	double_list.Delete(1);
	double_list.PrintList();
	double_list.Length();
	double_list.Retrieve(2, double_item);
}