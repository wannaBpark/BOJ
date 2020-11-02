#include <cstdio>
int ans = 0;
int N, M;
int pick[109],A[1000];
void dfs(int cnt, int lastIndex)
{
	if (cnt == 3) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			printf("%d ", pick[i]);
			sum += A[pick[i]];
		}
		printf("\n");
		if (ans < sum && sum <= M) ans = sum;
		return; //재귀스택 쌓이지 않도록. 중요!
	}
	for (int i = lastIndex+1; i < N; i++) {
		pick[cnt] = i;
		dfs(cnt + 1,i);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	dfs(0, -1);
	printf("%d\n", ans);
	return 0;
}