#include <cstdio>
#define ll long long

ll ans;
ll cntZero = 0;
int N;
ll pSum[100010];
ll A[100010];
ll dp[100010][4];

ll solve();

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%lld", &A[i]);
		pSum[i] = pSum[i - 1] + A[i];
		if (pSum[i] == 0) {
			++cntZero;
		}
	}

	ans = solve();
	printf("%lld", ans);

	return 0;
}

ll solve()
{
	ll ret;
	
	if (pSum[N] == 0) {
		ret = (cntZero - 1) * (cntZero - 2) / 2 * (cntZero - 3) / 3;
		return ret;
	} else if (pSum[N] % 4 != 0) {
		return -1;
	}
	// dp[idx][i번나눌수있는 경우의 수]
	// idx까지 i번째로 나눌수 있는 경우의 수
	ll avg = pSum[N] / 4;
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = 1;
	}
	for (int j = 1; j < 4; ++j) {
		ll k = j * avg;
		for (int i = 1; i <= N; ++i) {
			dp[i][j] = dp[i - 1][j];
			if (pSum[i] == k) {
				dp[i][j] += dp[i - 1][j - 1];
				//해당 i = idx에서 j번째 구간을 자르고, 이전까지(i-1)의 j-1구간을 자르는 경우를 택함을 뜻함.
			}
			//이미 자른것들의 경우의 수를 더해줌
		}
	}
	//N-1까지 잘랐을때, avg*4가 A[n]인것보장? ***************

	//N에서 3번째를 자를 순 없으므로.

	return dp[N - 1][3];
}