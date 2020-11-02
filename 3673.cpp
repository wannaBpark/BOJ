#include <cstdio>
const int MAX = 1e6+1;
long long pSum[50001] = { 0, }, N, M;

//나머지 배열 rem
int main()
{
	freopen("input.txt", "r", stdin);
	int c; scanf("%d", &c);
	while (c--) {
		scanf("%lld%lld", &M, &N);
		long long rem[MAX] = { 0, };
		long long ans = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &pSum[i]);
			pSum[i] += pSum[i - 1];
			rem[pSum[i] % M]++;
		}
		ans += rem[0];
		for (int i = 0; i < M; i++) {
			ans += (rem[i] * (rem[i] - 1)) / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}