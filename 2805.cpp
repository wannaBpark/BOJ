#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
ll A[1000010];
ll N, M;
ll ans = 0;
ll cal(ll mid) 
{
	ll sum = 0;
	for (int i = 0; i <N; i++) sum += (A[i]>mid) ? A[i]-mid : 0;
	return sum;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//이진탐색을 살짝 꼰 문제, mm에 배열의 최댓값저장해주고
	// 0,mm을 이진탐색으로 mid를 빼준값을 싹다 계산해줌

	ll mm = 0;
	int i = 0;
	scanf("%lld%lld", &N,&M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		mm = max(mm, A[i]);
	}
	ll start = 0, end = mm;
	while (start <= end) {
		ll mid = (start + end) / 2;
		ll result = cal(mid);
		if (result >= M) {
			ans = max(ans, mid);
			start = mid + 1;
		}
		else end = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}