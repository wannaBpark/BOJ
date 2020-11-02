#include <cstdio>
#include <map>
#include <math.h>
//싹다 나누기 -> 그 수보다 작은 소수로만 나누기 -> 에라토스테네스 체 연산 제곱부터 연산
#define MAX_N 2000001
#define ll long long
using namespace std;
ll N,i,j, ans = 0,index=0;
map<ll, ll> map1;
ll Sum[1000000] = { 0, };
ll P[MAX_N];
ll chk[MAX_N] = { 0, };
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%lld", &N);
	for (i = 2; i*i<=N; i++) {
		for (j = i*i; j <= N; j+=i) {
			chk[j] = 1;
		}
	}
	for (i = 2; i <= N; i++)
		if (chk[i] == 0) P[index++] = i;
	for (i = 0; i < index; i++)
		Sum[i] = Sum[i - 1] + P[i];
	ll left = 0, right = 0,sum=0;
	while (right <= index) {
		if (sum == N) ++ans;
		if (sum >= N) sum -= P[left++];
		else sum += P[right++];
	} //투 포인터 활용해서 
	//printf("\n");
	//for (i = 0; i < index; i++) {
	//	Sum[i] = Sum[i - 1] + P[i];
	//	//printf("%lld ", Sum[i]);
	//	if (Sum[i] == N)           ::맵 자료구조 활용해서 2015번과 유사하게 풀음
	//		++ans;
	//	ans += map1[Sum[i] - N];
	//	++map1[Sum[i]];
	//}
	printf("%lld\n", ans);
	return 0;
}

