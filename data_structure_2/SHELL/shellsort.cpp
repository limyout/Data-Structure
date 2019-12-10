#include <iostream>
#include <math.h>
#include <fstream> 
#include "shellsort.h"

using namespace std;

void insertionsort(int *A, int size, int start, int h) {
	int index, review, key;

	for (index = start + h; index <= size; index = index + h) {
		key = A[index];
		for (review = index - h; review >= start && A[review] > key; review = review - h) {
			A[review + h] = A[review];
		}
		A[review + h] = key;
	}
}


void shellsort(int *A, int size, int K) {
	int i = 0, gap = 0;
	if (K == 1) {
		insertionsort(A, size - 1, 0, 1);
	}
	else if (K == 2 || K == 3) {
		while (gap <= size) {
			gap = (int(pow(K, i++)) - 1) / (K - 1);
		}
		while (size) {
			if (gap == 0) gap = 1;
			for (i = 0; i < gap; i++) {
				insertionsort(A, size - 1, i, gap);
			}
			if (gap == 1) break;
			gap = gap / K;
		}
	}
	else {
		cout << "k�� ���� ������ ������ϴ�." << endl;
	}
}

int main() {

	ifstream input("input.txt");
	int size = 0;
	int k = 0;


	int *fileInNum = new int[100];
	int *arr = new int[100];

	if (input.fail()) {
		cout << "������ ���� �� �����߽��ϴ�." << endl;
		return 1;
	}

	while (!input.eof()) {
		input >> fileInNum[size];
		arr[size] = fileInNum[size];
		size++;
	}

	cout << "������ �������� ���� : " << size << endl;
	cout << "���ݺ� : ";
	cin >> k;


	shellsort(arr, size, k);

	for (int x = 0; x < size; x++) {
		cout << arr[x] << " ";
	}

	system("pause");

	return 0;
}