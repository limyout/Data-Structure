#include "pch.h"
#include <cstdlib>
#include <iostream>

#include "DoublyListP.h"

using namespace std;

listClass::listClass() {
	Count = 0;
	Head = NULL;
	Temp = NULL;
}

listClass::listClass(const listClass& L)
{
	Count = L.Count;
	if (L.Head == NULL)
		Head = NULL;
	else
	{
		Head = new node;
		Head->Data = L.Head->Data;
		Nptr Temp1 = Head;
		for (Nptr Temp2 = L.Head->Next; Temp2 != NULL; Temp2 = Temp2->Next)
		{
			Temp1->Next = new node;
			Temp1 = Temp1->Next;
			Temp1->Data = Temp2->Data;
		}
		Temp1->Next = NULL;
	}
}
listClass::~listClass()
{
	while (!IsEmpty()) {
		Delete(1);
	}

}

void listClass::Insert(int Position, int Item) {
	Nptr n = new node;
	n->Next = NULL;
	n->Data = Item;

	if (Head != NULL) {

		Temp = Head;

		if ((Count+1) == Position) {
			cout << "Listlength " << Count << endl;
			for (int i = 1; i < (Position - 1); i++) {
				Temp = Temp->Next;
			}
			Temp->Next = n;
			n->Prev = Temp;
		}
		else {
			cout << "Listlength " << Count << endl;
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

void listClass::Delete(int Position) {
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

void listClass::Retrieve(int Position, int & item) {
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
		cout << "Temp->Data : " << Temp->Data << endl;
		item = Temp->Data;
		cout << "copied item : " << item << endl;
	}
}


bool listClass::IsEmpty() {
	return (Count == 0);
}

int listClass::Length() {
	cout << "Length is "<< Count << endl;
	return 0;
}

void listClass::PrintList() {
	Temp = Head;
	for (int i = 1; i < Count+1; i++) {
		cout << i << " : " << Temp->Data << endl;
		Temp = Temp->Next;
	}
}

int main()
{
	listClass Paua;
	int item;

	Paua.Insert(1, 1);
	Paua.PrintList();
	Paua.Insert(2, 2);
	Paua.PrintList();
	Paua.Insert(3, 3);
	Paua.PrintList();
	Paua.Insert(3, 4);
	Paua.PrintList();
	Paua.Insert(5, 2);
	Paua.PrintList();
	Paua.Delete(4);
	Paua.PrintList();
	Paua.Delete(1);
	Paua.PrintList();
	Paua.Length();
	Paua.Retrieve(3, item);
	Paua.PrintList();
	cout << "item : " << item << endl;
}
