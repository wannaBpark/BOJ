#include <iostream>
#include <algorithm>
using namespace std;
#define dist(i,j) { abs(i-j)%1000 }

int N, T,I,J;
int p[20100],Rank[20100];
char c;
int find(int a)
{
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(a);
}
int main()
{
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) p[i] = 0;
		cin >> c;
		while (c != 'O') {
			if (c == 'E') {
				cin >> I;
				cout << dis(I) << endl;
			}
			else if (c == 'I') {
				cin >> I >> J;
				merge(I, J);
			}
			cin >> c;
		}
	}
	return 0;
}