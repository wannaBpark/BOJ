#include <cstdio>
#define swap(a,b) {auto tmp = a; a=b;b=tmp;}
int main()
{
	int N; 
	int A[51], B[51];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			if (A[i] < A[j]) swap(A[i], A[j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (B[i] > B[j]) swap(B[i], B[j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += A[i] * B[i];
	}
	printf("%d\n", ans);
}