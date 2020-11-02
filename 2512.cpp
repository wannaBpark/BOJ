#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
int A[10010];
int N,M;
int ans = 0;
int cal(ll mid)
{
	int sum = 0;
	for (int i = 0; i <N; i++) sum += (A[i] < mid) ? A[i] : mid;
	return sum;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int mx = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]),mx = max(A[i],mx);
	scanf("%d", &M);
	int start = 0, end = mx;
	while (start <= end) {
		int mid = (start + end) / 2;
		int result = cal(mid);
		if (result <= M) {
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}