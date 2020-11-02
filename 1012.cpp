#include <cstdio>
int T,M,N,K,ans=0;
int A[52][52];
int chk[52][52];
int dx[4] = { -1,1,0,0 }; //»óÇÏÁÂ¿ì
int dy[4] = { 0,0,-1,1 };
void dfs(int x, int y)
{
	if (x < 1 || y < 1 || x > N || y > M) return;
	for (int i = 0; i < 4; i++) {
		if(!chk[x+dx[i]][y+dy[i]] && A[x + dx[i]][y + dy[i]] == 2){
			chk[x + dx[i]][y + dy[i]] = 1;
			dfs(x + dx[i], y + dy[i]);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	int a, b;
	while (T--) {
		scanf("%d%d%d", &M, &N, &K);
		ans = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				A[i][j] = 1,chk[i][j]=0;
		while (K--) scanf("%d%d", &a, &b), A[b+1][a+1] = 2;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (A[i][j]==2 && !chk[i][j]) dfs(i, j), ++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}