#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;

void InsertionSort(int* array, int p, int r);
void HybridQuickSort(int* array, int p, int r);
int Partition(int* array, int p, int r);
void Swap(int* a, int* b);
int Mid(int* array, int a, int b, int c);
int Rand(int p, int r);

void HybridQuickSort(int* array, int p, int r) {
	if (p < r) {
		if (r - p + 1 <= 10) return InsertionSort(array, p, r);
		int a, b, c, pivot;

		srand((unsigned int)time(NULL));
		a = Rand(p,r);
		b = Rand(p,r);
		c = Rand(p,r);
		while(!(a!=b&&b!=c&&a!=c)){	
			b = Rand(p,r);
			c = Rand(p,r);
		}

		pivot = Mid(array, a, b, c);

		Swap(&array[pivot], &array[r]);

		int q = Partition(array, p, r);
		HybridQuickSort(array, p, q - 1);
		HybridQuickSort(array, q + 1, r);
	}
}
void InsertionSort(int* array, int p, int r) {
	int i, j, key;
	for (j = p + 1; j <= r;j++) {
		key = array[j];
		i = j - 1;
		while (i >= p && array[i] > key) {
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;
	}
}
int Partition(int* array, int p, int r) {
	int x, i, j;
	x = array[r];
	i = p - 1;
	for (j = p; j <= r - 1; j++) {
		if (array[j] <= x)
			Swap(&array[++i], &array[j]);
	}
	Swap(&array[i + 1], &array[r]);
	return i + 1;
}
int Rand(int p, int r){
	int a = rand() % (r - p + 1) + p;
	return a;
}
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int Mid(int* array, int a, int b, int c) {
	if (array[a] >= array[b]) {
		if (array[b] >= array[c]) return b;
		else if (array[a] >= array[c]) return c;
		else return a;
	}
	else {
		if (array[a] >= array[c]) return a;
		else if (array[b] >= array[c]) return c;
		else return b;
	}

}

int main(void) {
	clock_t start, end;
	float delay;
	ifstream inFile("input2-1.txt");
	ofstream outFile("output2-1.txt");
	int* A = (int*)malloc(sizeof(int) * (200005));
	int cnt = 1;
	for (cnt; !inFile.eof(); cnt++)
		inFile >> A[cnt];

	cnt -= 2;
	start = clock();
	HybridQuickSort(A, 1, cnt);
	end = clock();
	delay = (float)(end - start) / CLOCKS_PER_SEC;

	for (int i = 1; i <= cnt; i++)
		outFile << A[i] << " ";
	outFile << endl << fixed << delay <<" s" <<endl;

	free(A);
	inFile.close();
	outFile.close();
}
