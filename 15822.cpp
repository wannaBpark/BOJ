#include <cstdio>
#define dist(a,b) (a-b)*(a-b)
#define min(a,b) (a<b) ? a : b
int N,ans=0;
long long X[2001];
long long Y[2001];
long long DP[2001][2001] = { 0, };
long long F(int i, int j)
{
	if (i <=0  || j <=0) return 0;
	if (DP[i][j]) return DP[i][j];
	DP[i][j] = dist(X[i], Y[j])+
		min(min(F(i - 1, j - 1), F(i - 1, j)), F(i, j - 1));
	return DP[i][j];
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &X[i]);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &Y[i]);
	DP[1][1] = dist(X[1], Y[1]);
	printf("%lld\n", F(N,N));
	return 0;
}