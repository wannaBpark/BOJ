#include <cstdio>
#include <map>
#include <math.h>
//�ϴ� ������ -> �� ������ ���� �Ҽ��θ� ������ -> �����佺�׳׽� ü ���� �������� ����
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
	} //�� ������ Ȱ���ؼ� 
	//printf("\n");
	//for (i = 0; i < index; i++) {
	//	Sum[i] = Sum[i - 1] + P[i];
	//	//printf("%lld ", Sum[i]);
	//	if (Sum[i] == N)           ::�� �ڷᱸ�� Ȱ���ؼ� 2015���� �����ϰ� Ǯ��
	//		++ans;
	//	ans += map1[Sum[i] - N];
	//	++map1[Sum[i]];
	//}
	printf("%lld\n", ans);
	return 0;
}

