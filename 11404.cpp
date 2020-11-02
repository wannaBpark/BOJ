#include <cstdio>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
int N, M;
ll s, e, d;
ll dist[101][101];
int main()
{
	freopen("input.txt", "r", stdin);
	memset(dist, 0, sizeof(dist));
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%lld %lld %lld", &s, &e, &d);
		if(!dist[s][e]) dist[s][e] = d;
		else dist[s][e] = min(dist[s][e], d);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(i!=j && !dist[i][j]) dist[i][j] = 100000;
			//printf("%lld ", dist[i][j]);
		}
		//printf("\n");
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == 100000) printf("0 ");
			else printf("%lld ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}