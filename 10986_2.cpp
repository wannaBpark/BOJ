#include <cstdio>
#define ll long long
ll N, M,ans=0;
ll pSum[1001000];
ll cntNamu[1010];
int main()
{
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &pSum[i]); 
		pSum[i] += pSum[i - 1];
		cntNamu[pSum[i] % M]++;
	}
	ans += cntNamu[0];
	for (int i = 0; i < M; i++)
		ans += cntNamu[i] * (cntNamu[i] - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}