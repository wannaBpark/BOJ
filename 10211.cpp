//동적계획법 - max(이전까지의 최적 subarray, 현재위치에서 시작하는 subarray)
#include <cstdio>
#define max(a,b) a>b ? a: b
int A[1001],DP[1001];
int main()
{
	freopen("input.txt", "r", stdin);
	int TC, N;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
		}
		int mx=DP[0]=A[1];
		DP[0] = 0;
		for (int i = 1; i <= N; i++) {
			DP[i] = max(DP[i - 1] + A[i], A[i]);
			mx = max(DP[i],mx); //이전까지 값을 더하거나 처음부터 시작하거나.
		}
		printf("%d\n", mx);
	}
	return 0;
}

// pSum 완전탐색

//#include <cstdio>
//#define max(a,b) a>b ? a: b
//int pSum[1001];
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int TC, N;
//	pSum[0] = 0;
//	scanf("%d", &TC);
//	while (TC--) {
//		scanf("%d", &N);
//		for (int i = 1; i <= N; i++) {
//			scanf("%d", &pSum[i]);
//			pSum[i] += pSum[i - 1];
//		}
//		int mx = pSum[1];
//		for (int i = 1; i <= N; i++) {
//			for (int j = 0; j < i; j++) {
//				mx = max(pSum[i] - pSum[j], mx);
//			}
//		}
//		printf("%d\n", mx);
//	}
//	return 0;
//}