#include <cstdio>
#include <map>
#define MAX_N 200000
#define ll long long
using namespace std;
ll N, K,ans=0;
map<ll, ll> map1;
ll P[MAX_N];
ll A[MAX_N];
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%lld %lld", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		//if (A[i] == K) ++ans; //원소 하나
	}
	P[0] = A[0];
	for (int i = 1; i < N; i++) {
		P[i] = P[i - 1] + A[i];
	}
	for (int i = 0; i < N; i++) {
		if (P[i] == K)
			++ans;
		ans += map1[P[i] - K];
		map1[P[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}
	
	///*for (int i = 0; i < N; i++) {
	//	printf("%d\n", P[i]);
	//}*/
	//while (!(length> N)) {
	//	for (int i = length-1; i < N; i++) {
	//		/*tmp = i - length;
	//		printf("%d %d %d %d %d %d\n", i, length,tmp, P[i], P[i - length],K);	*/		
	//		if ( (i-length) < 0 && P[i] == K) {
	//			++ans;
	//		}
	//		else if ( (P[i] - P[i - length]) == K) {
	//			++ans;
	//			//printf("%d %d %d %d\n", i, length, P[i], P[i - length]);
	//		}
	//	}	
	//	length++;
	//}
	
