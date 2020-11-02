#include <cstdio>
#include <math.h>
int fac(int a) {
	if (a <= 1) return 1;
	return a*fac(a - 1);
}
int main()
{
	int N, M,a,ans;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
	}	
	printf("%d\n", ans = (N == M) ? fac(N) : pow(10, N) - pow(10 - M, N));
}