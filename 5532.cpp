#include <cstdio>
int max(int a, int b) { return a > b ? a : b; }
int n(int a, int b) { return a%b ? a / b + 1 : a / b; }
int L, A, B, C, D;
int main()
{
	scanf("%d%d%d%d%d", &L, &A, &B, &C, &D);
	printf("%d", L-max(n(A,C),n(B,D)));
	return 0;
}