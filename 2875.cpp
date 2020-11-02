#include <cstdio>
int min(int a, int b) {return a > b ? b : a; }
int N, M, K,ans;
int main()
{
	freopen("input.txt", "r", stdin); 
	scanf("%d%d%d", &N, &M, &K); 
	printf("%d\n", min(min(N / 2, M), (N + M - K) / 3));
	return 0;
}
/*
N=7, M=4의 경우를 가정해보자.
최대 3=min(N/2,M)팀을 만들 수 있고, 남는 인원은 여자 한 명, 남자 한 명, 합해서 두 명이다.
즉, K가 1이나 2일 경우 남는 인원에서 빼기 때문에 어느 쪽에서 빼든 상관없다.
K가 3일때가 문제인데, 이미 결정되있던 1팀을 깨야한다.
이 경우에도 K가 3,4,5일때는 어차피 있던 1팀을 깨는건 마찬가지고,
K가 6,7,8일때도 2팀을 깨는건 마찬가지다.
따라서 (N+M-K)/3가 성립한다.(한팀을 더 깨려면 K가 3씩 늘어나는 규칙)
*/