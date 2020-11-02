#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
int A[1000010];
int K, N;
int ans = 0;
int cal(ll mid)
{
	int sum = 0;
	for (int i = 0; i <K; i++) sum += (A[i]>=mid) ? A[i]/mid : 0;
	return sum;
}
int main()
{
	freopen("input.txt", "r", stdin);

	ll mm = 0x7fffffff;
	scanf("%d%d", &K, &N);
	for (int i = 0; i < K; i++) scanf("%lld", &A[i]);
	ll start = 1, end = mm;
	while (start <= end) {
		ll mid = (start + end) / 2;
		int result = cal(mid);
		if (result >= N) {
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}