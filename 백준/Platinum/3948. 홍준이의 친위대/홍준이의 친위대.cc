#include <cstdio>
#define ll long long
#define updown 0
#define downup 1
int T, N, mx = 2;
ll dp[2][25];
ll comb[25][25];

void combination();

int main()
{
	scanf("%d", &T);

	combination();
	dp[0][0] = dp[1][0] = dp[1][1] = dp[0][1] = 1;
	while (T--) {
		scanf("%d", &N);
		
		if (N == 1) {
			puts("1");
			continue;
		} else if (mx >= N) {
			printf("%lld\n", dp[updown][N] + dp[downup][N]);
			continue;
		}


		for (int k = 2; k <= N; ++k) {
			if (dp[0][k] != 0) 
				continue;
			for (int l = 0; l < k; ++l) {
				int r = k - l - 1;
				int upd = l & 1 ? downup : updown;
				dp[upd][k] += (dp[upd][l] * dp[downup][r] * comb[k - 1][l]);
			}
		}
		mx = N;
		printf("%lld\n", dp[updown][N] + dp[downup][N]);
	}

	return 0;
}

void combination()
{
	for (int i = 0; i <= 20; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == j || j == 0)
				comb[i][j] = 1;
			else if (j == 1)
				comb[i][j] = i;
			else
				comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
}