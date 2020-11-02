#include <stdio.h>
#include <math.h>
long long int N, K,max=100000000,ans=0;
long long int A[11] = { 0, };
int index;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%lld %lld", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		if ((K - A[i]) < max && (K - A[i]) >= 0 ){
			max = K - A[i];
			index=i;
		}
	}
	for (int i = index; i >=0; i-- ) {
		if ((K / A[i]) > 0 && K!=0) {
			ans += K / A[i];
			K = K%A[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}