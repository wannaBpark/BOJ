#include <cstdio>
int t,n;
int A[110];
int gcd(int a, int b)
{
	if (b == 0) return a;
	else gcd(b, a%b);
}
int main()
{
	scanf("%d", &t);
	while (t--) {
		long long ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &A[i]);
		for (int j = 0; j < n - 1; j++) {
			for (int i = j + 1; i < n; i++) {
				ans += (long long)gcd(A[i], A[j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}