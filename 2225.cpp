#include <cstdio>
int N, K;
int dp[210][210];
const int mod = 1000000000;
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= K; i++) dp[0][i] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = (dp[i-1][j]+dp[i][j - 1])%mod;
			//dp[i][j]�� dp[0~i-1][j-1]�� �� + dp[i][j-1]���� 0�� ���Ѱ�
			//dp[i-1][j]  = dp[i-1][j-1]�� ���� �� : ǥ����
			//dp[i][j-1] : �����Ϳ��� 0�� ���ϴ� ���
		}
	}
	/*for (int i = 1; i <= N; i++) {
		printf("%d: ", i);
		for (int j = 1; j <= N; j++) {
			printf("%d ", dp[i][j]);
		}
		puts("");
	}*/
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; i++) {
			printf("%d ", dp[i][j]);
		}
		puts("");
	}*/
	printf("%d\n", dp[N][K]);
	return 0;
}