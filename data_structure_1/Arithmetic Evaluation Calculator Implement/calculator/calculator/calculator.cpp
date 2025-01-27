#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

#include "genericStackDL.h"

using namespace std;


struct operatorStruct
{
	string op;
	int precedence;
};



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
	else if(Count > 100){
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

template<typename T>
int stackClass<T>::Check() {
	if (Count == 1) return 2;
	if (Count == 0) return 1;
	else return 0;
}

bool isDigit (char c)
{
	return (c >='0' && c <= '9');
}

bool isOp (char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '.' );
}

int getPrecedence (char c)
{
	switch (c)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '(': return 0;
		case ')': return 0;
		case '.': return 5;
			return -1;
	}
	
}

double operate (double val1, double val2, char op)
{
	if (op == '+') return val1 + val2;
	if (op == '-') return val1 - val2;
	if (op == '*') return val1 * val2;
	return val1 / val2;
}

double pow(double val1, double val2)
{

	double temp = val1;
	for (int i = 1; i < val2; i++) {
		temp = val1 * temp;
	}
	return temp;
}

double log(double val1)
{
	return log10(val1);
	
}

double sqrval(double val1)
{
	return sqrt(val1);
}

char* remove_space(char* str)
{
	char* pstr = str;
	while (*pstr)
	{
		if (*pstr != ' ')
			*str = *pstr;
		str++; 

		pstr++;
	}
	*str = '\0';
	return str;
}


double evaluate (string s)
{
	stackClass<double> vals;
	stackClass<char> ops;



	double val, prev = 0;
	int pos = 0;
	int i = 0, k;
	int temp = 0;
	int z = 1;



	while (pos < s.length()){
		char spot = s[pos];
		k = pos;

		char* remove_space(char* spot);


		if (spot == 'p' && s[k + 1] == 'o' && s[k + 2] == 'w') {
						pos = pos + 3;
						while (1) {
									if (s[pos] == '(') {
										ops.Push(s[pos]);
									}
									else if (isDigit(s[pos])) {
										vals.Push(s[pos] - 48);
										if (ops.GetTop() == '.') {
											val = ((s[pos] - 48) * 0.1);
											vals.Pop();
											prev = vals.GetTop();
											vals.Pop();
											vals.Push(prev + val);
											ops.Pop();
										}
									}
									else if (s[pos] == '.') {
										ops.Push(s[pos]);
							}
							else if (s[pos] == ',') {
								ops.Push(s[pos]);
							}
							else if (s[pos] == ')') {
										if (ops.GetTop() != ',') {
											cout << "syntax error" << endl;
											return 0;
										}
								val = vals.GetTop();
								vals.Pop();
								prev = vals.GetTop();
								vals.Pop();
								vals.Push(pow(prev, val));
								ops.Pop();
								break;
							}
							pos++;
			}
		}
		else if (spot == 'l' && s[k + 1] == 'o' && s[k + 2] == 'g') {
			pos = pos + 3;
			while (1) {
				if (s[pos] == '(') {
					ops.Push(s[pos]);
				}
				else if (isDigit(s[pos])) {
					vals.Push(s[pos] - 48);
					if (ops.GetTop() == '.') {
						val = (vals.GetTop() * 0.1);
						vals.Pop();
						prev = vals.GetTop();
						vals.Pop();
						vals.Push(prev + val);
						ops.Pop();
					}
				}
				else if (s[pos] == '.') {
					ops.Push(s[pos]);
				}
				else if (s[pos] == ')') {
					val = vals.GetTop();
					vals.Pop();
					vals.Push(log(val));
					ops.Pop();
					pos++;
					break;
				}
				pos++;

			}
		}
		else if (spot == 's' && s[k + 1] == 'q' && s[k + 2] == 'r' && s[k + 3] == 't') {
			pos = pos + 4;
			while (1) {
				if (s[pos] == '(') {
					ops.Push(s[pos]);
				}
				else if (isDigit(s[pos])) {
					vals.Push(s[pos] - 48);
					if (ops.GetTop() == '.') {
						val = (vals.GetTop() * 0.1);
						vals.Pop();
						prev = vals.GetTop();
						vals.Pop();
						vals.Push(prev + val);
						ops.Pop();
					}
					k = pos;
					if (isDigit(s[k - 1])) {
						while (isDigit(s[k - 1 + i])) {
							vals.Push(s[k - 1 + i]);
							pos++;
							i++;
						}
						while (i > 0) {
							i--;
							val = (s[k - 1 + i] - 48) * (10 * z);
							temp += val;
							vals.Pop();
							z = 10 * z;
						}
						vals.Pop();
						vals.Pop();
						temp = temp / 10;
						vals.Push(temp);
						pos = pos - 2;
					}

				}
				else if (s[pos] == '.') {
					ops.Push(s[pos]);
				}
				else if (s[pos] == ')') {
					val = vals.GetTop();
					vals.Pop();
					vals.Push(sqrval(val));
					ops.Pop();
					pos++;
					break;
				}
				pos++;

			}
		}
		else {
			if(isDigit(spot)) {
				if (isDigit(s[k - 1])) {
					while (isDigit(s[k - 1 + i])){
						vals.Push(s[k - 1 + i]);
						pos++;
						i++;
					}
					while (i > 0) {
						i--;
						val =  (s[k - 1 + i]-48) * (10 * z);
						temp += val;
						vals.Pop();
						z = 10 * z;
					}
							vals.Pop();
							temp = temp / 10;
							vals.Push(temp);
							pos = pos - 2;
						}
						else {
							k = pos;
							val = (double)(spot - '0');
								if (ops.GetTop() == '.') {
									ops.Pop();
									prev = vals.GetTop();
									val = prev + (val * 0.1);
									vals.Pop();
								}
							vals.Push(val);
						}
					}

					else if (isOp(spot)) {
						if (pos > 0) {
							if (spot == '(') {
								ops.Push(spot);
							}
							else if (spot == ')') {
								while (ops.GetTop() != '(') {
									val = vals.GetTop();
									vals.Pop();
									prev = vals.GetTop();
									vals.Pop();
									val = operate(prev, val, ops.GetTop());
									ops.Pop();
									vals.Push(val);
									if (ops.GetTop() != '(') {
										cout << "syntax error" << endl;
									}
								}
								ops.Pop();
							}
							else if (spot == '.'){
								ops.Push(spot);
							}
							else if (getPrecedence(ops.GetTop()) > getPrecedence(spot)) {
								val = vals.GetTop();
								vals.Pop();
								prev = vals.GetTop();
								vals.Pop();
								val = operate(prev, val, ops.GetTop());
								ops.Pop();
								ops.Push(spot);
								vals.Push(val);
							}
							else {
								ops.Push(spot);
							}
						}
						else {
							ops.Push(spot);
						}
						}

			cout << "vals.PrintList : " << endl;
			vals.PrintList();
			cout << "ops.PrintList : " << endl;
			ops.PrintList();

			cout << endl << endl << endl;
					pos++;
		}

}	



	if (vals.Check() == 2 && ops.Check() == 1) {
		return vals.GetTop();
	}
	else {
		cout << "syntax error" << endl;
	}
	
}

int main()
{
	cout << evaluate("((pow( 2.0 , 3.0) - log( 2.0 )) * sqrt( 11.0 ))") << endl;
	return 0;
}