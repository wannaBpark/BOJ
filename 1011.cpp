#include <cstdio>
typedef long long ll;
ll A[100010];
int T;
//파스칼의 삼각형
//원래 dp로 생각
//int q(int s, int k, int cnt) {
//	if (s == b-1) return cnt;
//	return min(min(q(s + k + 1, k + 1, cnt + 1), q(s + k - 1, k - 1, cnt + 1)),
//		q(s + k, k, cnt + 1));
//}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (ll i = 1; i <= 7; i++)
		A[i] = (i & 1) ? (i / 2 + 1)*(i / 2 + 1) : A[i - 1] + ((i-1) / 2 + 1);
	ll x, y;
	while (T--) {
		scanf("%lld%lld", &x, &y); ll dif = y - x; ll i = 1;
		while (A[i++] < dif) {}
		printf("%lld\n", i-1);
	}
	return 0;
}