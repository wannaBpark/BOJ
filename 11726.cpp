#include <stdio.h>
#define NAMU 10007
int N;
long long int DP[1001] = { 0, };
///f(i) = f(i-1) +f(i-2)
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	DP[1] = 1; DP[2] = 2;
	if (N>=3) {
		for (int i = 3; i <= N; i++) {
			DP[i] = (DP[i - 1] + DP[i - 2])%NAMU; //Q.한꺼번에 나머지 연산했다간 아작난다.왤까?
		}
	}
	printf("%lld\n", DP[N]);
	//원래 divide하는 선이 지나가면서 생기는 경우를 구하려고했으나 중복발생
	//중복발생하는 기준이 매우 애매했음
	//이전값을 참고해서 중복을 일어나지 않게 하는 것이 DP의 묘미
	/*DP[1] = 1;
	DP[2] = 2;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < i; j++) {

		}
		ans += DP[i] + DP[N - i];
	}*/
	return 0;
}