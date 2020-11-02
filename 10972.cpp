#include <iostream>
#include <algorithm>
using namespace std;
int A[10100], cpy[10100];
int N;
int main()
{
	cin >> N;
	bool isNext = true, isAns = false;
	for (int i = 0; i < N; i++) cin >> A[i], cpy[i] = A[i];
	do {
		if (isAns) {
			for (int i = 0; i < N; i++) cout << A[i] << " ";
			return 0;
		}
		for (int i = 0; i < N; i++) {
			if (A[i] == cpy[i]) isNext = true;
			else {
				isNext = false; break;
			}
		}
		if (isNext) isAns = true;
	} while (next_permutation(A, A + N));
	cout << "-1" << endl;
	return 0;
}