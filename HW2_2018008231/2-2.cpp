#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

pair<int*, int*> ExtendedRodCut(int* p, int n) {
	int* r = (int*)malloc(sizeof(int) * (n + 5));
	int* s = (int*)malloc(sizeof(int) * (n + 5));
	int i, j, q;
	for (j = 1; j <= n; j++) {
		q = -1;
		for (i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	return make_pair(r, s);
}
void Print(int* p, int n) {
	pair<int*, int*> t = ExtendedRodCut(p, n);
	int* r = t.first;
	int* s = t.second;

	cout << r[n] << endl;

	while (n > 0) {
		cout << s[n] <<" ";
		n -= s[n];
	}
	cout << endl;
	free(t.first);
	free(t.second);
}

int main(void) {
	ifstream inFile("input2-2.txt");
	int n, i;
	inFile >> n;
	int* p = (int*)malloc(sizeof(int) * (n + 5));
	for (i = 1; i <= n; i++) inFile>>p[i];

	Print(p, n);

	free(p);
	inFile.close();
}
