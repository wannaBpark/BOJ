#include <cstdio>
#include <cstring>
char A[50], B[50];
int ans = 50, cnt = 0, dif;
int main()
{
	scanf("%s %s", &A, &B);
	dif = strlen(B) - strlen(A);
	for (int i = 0; i <= dif; i++) {
		cnt = 0;
		for (int j = i,k=0; i < strlen(B),k<strlen(A); j++,k++) {
			cnt += (B[j] != A[k]) ? 1 : 0;
			printf("%c", B[j]);
		}
		puts("");
		ans = ans > cnt ? cnt : ans;
	}
	printf("%d\n", ans);
	return 0;
}