#include <cstdio>
#include <string.h>
int main()
{
	char B[51];
	char A[51];
	int N;
	scanf("%d", &N);
	scanf("%s", &A);
	for (int i = 1; i < N; i++) {
		scanf("%s", &B);
		for (int j = 0; j < strlen(B); j++) {
			A[j] == B[j] ? A[j] = A[j] : A[j]='?';
		}
	}
	printf("%s", A);
}