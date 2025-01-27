#include "pch.h"
#include <iostream> 
#include <fstream> 

using namespace std;


	int arr[100];
	int start;
	int end;
	int key;
	int k;
	int num = 0;

	int KarySearch(int A[], int k, int start, int end, int key) {


			if (A[start] == key) {
				return (start + 1);
			}
			cout << "범위 : " << start << " " << end << endl;

				for (int i = 0; i < k; i++) {
					num = start + (((float)(end - start) / (float)k)) * i;
					if (A[num] == key) {
						return (num + 1);
					}
					else if (A[num] > key) {
						start = num - (((float)(end - start) / (float)k)) * 1;
						end = num;
						KarySearch(A, k, start, end, key);
						return (num + 1);
					}
				}

				KarySearch(A, k, end - ((end - start) / k), end, key);


	}


 int main() {

	ifstream input("input.txt");
	int i = 0, a = 0, start = 0, k = 0;


	cin >> k >> a;

	if (input.fail()) {
		cout << "파일을 여는 데 실패했습니다." << endl;
		return 1;

	}

	int *fileInNum = new int[100];
	int *arr = new int[100];

	while (!input.eof()) {
		input >> fileInNum[i];
		arr[i] = fileInNum[i];
		i++;
	}

	cout << KarySearch(arr, k, start, i, a) << "번 째 위치합니다." << endl;


	delete[] fileInNum;
	input.close();
	return 0;
}