#include <cstdio>
#include <math.h>
#include <algorithm>
#define max(a,b) (a>b) ? a:b
int C[100000][2];
double L[100000];
int N, K,Pi,x,y;
double len;
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &Pi);
		for (int j = 0; j < Pi; j++) {
			scanf("%d %d", &x, &y);
			//printf("%d %d\n", x, y);
			len = max(len, sqrt(pow(x, 2) + pow(y, 2)));
		}
		L[i] = len;
		len = 0;
	}
	
	sort(L, L + N);
	
	printf("%.2lf", pow(L[K - 1], 2));
	return 0;
}