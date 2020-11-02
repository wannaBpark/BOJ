#include <stdio.h>
#include <string.h>
#define MAX(a,b) (a>b) ? a:b;
#define W 0
#define V 1
int DP[100][100000] = { -1, };
int N, capacity;
int items[100][2];
int knapsak(int pos, int capacity)
{
	if (pos == N) return 0;
	int ret = DP[pos][capacity];

	if (ret != -1) return DP[pos][capacity];
	if(items[pos][W] <= capacity)
		ret = knapsak(pos + 1, capacity - items[pos][W]) + items[pos][V];
	ret = MAX(ret, knapsak(pos + 1, capacity));
	return DP[pos][capacity]=ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &capacity);
	memset(DP, -1, sizeof(DP));
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &items[i][W], &items[i][V]);
	}
	printf("%d\n", knapsak(0,capacity));
	return 0;
}