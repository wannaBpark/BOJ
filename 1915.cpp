#include <cstdio>
#include <algorithm>
using namespace std;
int N, M,ans=0;
char A[1010][1010];
int dp[1010][1010];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M;j++)
			scanf(" %c", &A[i][j]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i][j] == '1') {
				int a = dp[i - 1][j];
				int b = dp[i - 1][j - 1];
				int c = dp[i][j - 1];
				dp[i][j] = min(a, min(b, c))+1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	printf("%d", ans*ans);
	return 0;
}
//void chkSquare(int i, int j)
//{
//	bool isSquare = true;
//	if (i - 1 < 0 || j - 1 < 0) return;
//	if (A[i - 1][j - 1] == '1') {
//		int size = length[i - 1][j - 1];
//		for (int x = 1; x <= size; x++)
//			if (A[i][j - x] != '1') isSquare = false;
//		for (int x = 1; x <= size; x++)
//			if (A[i-x][j] != '1') isSquare = false;
//	}
//	if (isSquare) length[i][j] = length[i-1][j-1] + 1;
//}
//ÀüÃ¼Å½»ö.
