#include<cstdio>
#define min(a,b) a>b ? b:a
int N, M,K;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &K);
	while (K--) scanf("%d%d", &N, &M), N = min(N, M), printf("%d\n", 2 * N - 2);
	return 0;
}