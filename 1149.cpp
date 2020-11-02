#include <iostream>
#include <algorithm>
#define MN 1000
using namespace std;
int N;
int dp[MN + 1][4],A[MN+1][4];
//dp = 이전값과 비교. 빨강,파랑,초록으로 칠했을때 현재최솟값 = 이전것에서 같은색을 칠하지않은것+현재값
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i][1] >> A[i][2] >> A[i][3];
	dp[1][1] = A[1][1], dp[1][2] = A[1][2], dp[1][3] = A[1][3];
	for (int i = 2; i <= N; i++) {
		dp[i][1] = min(dp[i - 1][2] + A[i][1], dp[i - 1][3] + A[i][1]);
		dp[i][2] = min(dp[i - 1][1] + A[i][2], dp[i - 1][3] + A[i][2]);
		dp[i][3] = min(dp[i - 1][1] + A[i][3], dp[i - 1][2] + A[i][3]);
		printf("%d %d %d\n", dp[i][1], dp[i][2], dp[i][3]);
	}
	cout << min(min(dp[N][1], dp[N][2]), dp[N][3]) <<endl;
	return 0;
}