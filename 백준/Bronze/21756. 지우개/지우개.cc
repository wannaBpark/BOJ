#include <stdio.h>
int N;
int ans = 1;
int main()
{
	scanf("%d", &N);
	while (N = N / 2) {
		ans *= 2;
	}
	printf("%d", ans);
	return 0;
}