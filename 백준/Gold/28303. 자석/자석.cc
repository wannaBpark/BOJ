#include <iostream>
#include <limits.h>
using namespace std;
int N, K;
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> K;
	int a;
	long long ans = LLONG_MIN;
	long long mn = 1e18, mx = -1e18;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		//v.push_back(a);
		long long t1 = a - K * (i + 1);
		long long t2 = a + K * (i + 1);

		ans = t1 - mn > ans ? t1 - mn : ans;
		ans = mx - t2 > ans ? mx - t2 : ans;
		mn = mn < t1 ? mn : t1;
		mx = mx > t2 ? mx : t2;
	}
	cout << ans;
	return 0;
}