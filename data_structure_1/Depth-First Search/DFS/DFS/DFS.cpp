#include "pch.h"
#include <iostream>
#include <fstream> 
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
	while (!IsEmpty()) {
		Pop();
	}

}

template<typename T>
void stackClass<T>::Linking(char a, int temp)
{
	cout << "asd" << endl;

}


template<typename T>
void stackClass<T>::Push(T Item)
{
	node<T> *NewTop = new node<T>;
	NewTop->Data = Item;
	Top = NewTop;
	if (Count == 0) {
		Head = NewTop;
		Count += 1;
	}
	else if (Count > 0 && Count < 101) {

		Temp = Head;
		for (int i = 0; i < Count - 1; i++) {
			Temp = Temp->Next;
		}
		NewTop->Prev = Temp;
		Temp->Next = NewTop;
		Count += 1;
	}
	else if (Count > 100) {
		cout << "Addition on Full Stack" << endl << endl;

		Pop();
	}

}
template<typename T>
void stackClass<T>::Pop()
{
	if (IsEmpty()) {
		cout << "Deletion on Empty Stack" << endl;
		cout << Count << endl;
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
}

template<typename T>
T stackClass<T>::GetTop()
{
	if (Count > 0) {
		Temp = Head;
		for (int i = 0; i < Count - 1; i++) {
			Temp = Temp->Next;
		}
		return Temp->Data;
	}
	else {
		return 0;
	}
}


template<typename T>
bool stackClass<T>::IsEmpty()
{
	if (Count != 0) {
		return 0;
	}
	else {
		return 1;
	}
}

template<typename T>
bool stackClass<T>::IsFull()
{
	if (Count == MAX) {
		return 1;
	}
}

template<typename T>
void  stackClass<T>::PrintList() {
	Temp = Head;
	for (int i = 1; i < Count + 1; i++) {
		cout << i << "'s list : " << Temp->Data << "   " << endl << endl;
		Temp = Temp->Next;
	}
	cout << endl;
}


 int main() {

	char start, end;
	char *arr;
	string cpps;
	char temp = '1';
	char pretemp = '0';
	stackClass<char> base;
	char templog[10] = {};
	int path = 0;
	int k = 0, a = 0, x = 0;

	cin >> start >> end;

	temp = start;

	while (1) {

		ifstream input("sample_graph.txt");

		if (input.fail()) {
			cout << "파일을 여는 데 실패했습니다." << endl;
			return 1;
		}

		
		if (base.GetTop() == '7') {
			for (int i = 0; i < size_templog; i++) {
				if (templog[i] == '1') {
					while (base.GetTop() != '1') {
						base.Pop();
					}
					base.Push('7');
					break;
				}
			}
		}

		if (temp == pretemp) {
			for (int i = 0; i < size_templog; i++) {
				getline(input, cpps);
				arr = (char*)cpps.c_str();


				if ((cpps.length() == 5)) {
					for (int i = 1; i < cpps.length() + 1; i = i + 2) {
						if (i == 1 || i == 3) {
							continue;
						}
						else if (i >= 5) {
							temp = arr[i - 1];
							base.Pop();
							base.Push(temp);
						}
					}
					break;
				}
			}
			pretemp = '0';
			temp = '1';
			start = base.GetTop();
			goto here;
		}


		for (int i = 0; i < k; i++) {
			if (templog[i] == temp) {
				a++;
			}
		}
		base.Push(temp);
		pretemp = temp;
		templog[k] = temp;
		k++;



		if (x == a) {
			while (input.peek() != EOF) {
				here:
				getline(input, cpps);
				arr = (char*)cpps.c_str();

				

				if (start == end) {
					base.PrintList();
					while (!base.IsEmpty()) {
						base.Pop();
						path++;
					}
					cout << "path length: " << path << endl;
					return 0;
				}


				if (start == arr[0]) {
					for (int i = 1; i < (2 * ((cpps.length() / 2) + 1)); i = i + 2) {
						if (i == 1) {
							continue;
						}
						else if (i == 3) {
							temp = arr[i - 1];
						}
						else {
							if (arr[i - 3] > arr[i - 1]) {
								temp = arr[i - 1];
							}
						}
					}
					start = temp;
					break;
				}
			}
		}



		else if (x != a) {
			base.Pop();
			while (base.GetTop() != temp) {
				base.Pop();
			}
			while (input.peek() != EOF) {


				getline(input, cpps);
				arr = (char*)cpps.c_str();

				if (temp == arr[0]) {
					for (int i = 1; i < (2 * ((cpps.length() / 2) + 1)); i = i + 2) {
						if (i == 1 || i == 3) {
							continue;
						}
						else if (i == 5) {
							temp = arr[i - 1];
						}
					}
					start = temp;
					x++;
					break;
				}
			}
		}

		base.PrintList();
		input.close();

		cout << endl << endl << endl;
	}
	return 0;
}