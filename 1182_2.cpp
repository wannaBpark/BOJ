#include <cstdio>
int N, S,ans=0;
int A[22];
void backtracking(int index, int cnt)
{
	if (cnt == S && index>=0) ans++;
	for (int i = index + 1; i < N; i++) {
		backtracking(i, cnt + A[i]);
	}
}
int main()
{
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	backtracking(-1, 0);
	printf("%d\n", ans);
	return 0;
}