#include <cstdio>
#include <cstring>
int N, M, cnt = 1;
char A[1005][1005] = { 0 };
int visited[1005][1005] = { 0 };
int saved[1005][1005];
int ans = 0;
bool isOverlapped = false;
bool isRange(int i, int j)
{
	if ((i < 0 || j < 0 || i >= N || j >= M)) return false;
	return true;
}
void dfs(int i, int j)
{
	visited[i][j] = true;
	saved[i][j] = true;
	if (A[i][j] == 'N') i--;
	if (A[i][j] == 'S') i++;
	if (A[i][j] == 'W') j--;
	if (A[i][j] == 'E') j++;
	if (!isRange(i, j)) return;
	if (saved[i][j]) {
		isOverlapped = true;
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", visited[i][j]);
		}
		puts("");
	}
	puts("");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", saved[i][j]);
		}
		puts("");
	}
	puts("");

	if (!visited[i][j]) dfs(i, j);
	else if (visited[i][j]) {
		visited[i][j] = 0;

		return;
	}
	visited[i][j] = 0;

	return;
}
//wookje.dance/2018/03/31/boj-15559-내-선물을-받아줘/
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", &A[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
			int y = i, x = j;
			while (!visited[y][x]) {
				visited[y][x] = cnt;
				char c = A[y][x];
				if (c == 'S') y++; if (c == 'E') x++;
				if (c == 'N') y--; if (c == 'W') x--;
			}
			if (cnt++ == visited[y][x]) ans++; //cnt랑 visited가 같을때:겹치지 않고 새로운 경로.
		}
	printf("%d\n", ans);
	return 0;
}