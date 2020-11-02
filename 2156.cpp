#include <cstdio>
#include <algorithm>
using namespace std;
int N,mx=0;
int dp[10010],A[10001];
//dp[i] = i개의 포도주가 있을때 마실수 있는 최대양
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	dp[1] = A[1], dp[2] = A[2]+A[1];

	for (int i = 3; i <= N; i++) {
		//연속 0개 : dp[i-1]
		//dp[i-2]+dp[i]연속 한개: i-2번지까지의 최댓값+포도주
		//dp[i - 3] + A[i - 1] + A[i] 연속 두개: i-3 +(i-2세번연속제외)+이전것 + 현재것
		dp[i] = max(dp[i - 1], max(dp[i - 3] + A[i - 1] + A[i], dp[i - 2] + A[i]));
		
	}
	printf("%d\n", dp[N]);
	return 0;
}