#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
long long int a, d, x;
int mn = 0;
long long int ans = 1e16;
long long int nfloorRight(long long int n)
{
	long long int ret;
	ret = n * a + (d * (n - 1) * n / 2);
	return ret;
}
void binary_find(long long int l, long long int r)
{
	if (l > r) return;
	long long int res1 = nfloorRight(l);
	long long int res2 = nfloorRight(r);
	long long int mid = (l + r) / 2;
	// 둘다 되면, 작은 층으로
	if (res2 < x) return;

	bool isAns1 = (res1 >= x) ? true : false;
	bool isAns2 = (res2 >= x) ? true : false;
	if (isAns1) ans = min(ans, l);
	if (isAns2) ans = min(ans, r);
	
	if (isAns1 && isAns2) {
		return;
	}
	//하나만 되면, 반 쪼개서 이진탐색
	else if (!isAns1 && isAns2) {
		binary_find(l + 1, mid);
		binary_find(mid + 1, r - 1);
		return;
	}
	return;
}
int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		int floor = 10;
		scanf("%lld %lld %lld", &a, &d, &x);
		binary_find(1, x);
		//printf("%d %d\n", floor, ans);
		long long int cell = x- nfloorRight(ans - 1);
		printf("%lld %lld\n", ans, cell);
		ans = 1e16;
	}

	return 0;
}