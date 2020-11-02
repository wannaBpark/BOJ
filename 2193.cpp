#include <cstdio>
#define ll long long
ll fibo[90] = { 0, };
int N;
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	fibo[0] = 1; fibo[1] = 1;

	for (int i = 2; i < N; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	printf("%lld\n", fibo[N - 1]);
	return 0;
}