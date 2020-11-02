#include <cstdio>
int N, S, A[21];
int pick[21];
int ans = 0;
void dfs(int cnt, int lastIndex) //로또 문제와 비슷
{
	if (cnt > N) return;
	int sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += A[pick[i]];
	}
	if (sum == S && cnt) ++ans;
	for (int i = lastIndex + 1; i < N; i++) {
		pick[cnt] = i;
		dfs(cnt + 1, i);
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	dfs(0, -1);
	printf("%d\n", ans);
	return 0;
}