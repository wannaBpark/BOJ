#include <cstdio>
const int MAX = 1e6 + 1;
long long pSum[MAX] = { 0, }, rem[1000] = { 0, },N,M;
 //������ �迭 rem
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%lld%lld", &N, &M);
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
	/*for (int i = 0; i < N; i++) {
		for (int j = 1; i + j <= N; j++) {
			tmp = pSum[i + j] - pSum[j - 1];
			if (tmp%M == 0) {
				printf("%d %d\n", j, i+j);
				++ans;
			}
		}
	}*/            //����Ǯ��:������ �������� �� ��. �̷���� �ð��ʰ�
	printf("%lld\n", ans);
	return 0;
}