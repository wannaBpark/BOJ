#include <cstdio>
int T, N;
int dp[12];
//���� �Ϳ��� 1�� ���ϰų�, 2�����ϰų�, 3�� ���ϴ� ���
//�������� �����ϴ� ��.
int main()
{
	scanf("%d", &T); dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= 10; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	while (T--) scanf("%d", &N), printf("%d\n", dp[N]);
}