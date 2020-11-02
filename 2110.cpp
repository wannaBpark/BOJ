#include <cstdio>
#include <algorithm>
using namespace std;
int N, C;
int A[200010];
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);
	int start = 1, end = A[N - 1];
	int ans = 0; //
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 1, next = 0;
		for (int i = 1; i < N; i++) {
			if (A[i] - A[next] >= mid) ++cnt, next = i;
		}
		//printf("%d %d %d %d %d\n", start, end, mid, cnt, C);
		if (cnt < C) end = mid - 1; //
		else start = mid + 1, ans = max(ans, mid);
	}
	printf("%d\n", ans);
	return 0;
}