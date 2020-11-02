#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int visited[305][305];
int A[305][305];
int N, M;
queue<pair<int, int>> q;
bool isRange(int i, int j)
{
	if (i<1 || i>N || j<1 || j>M) return false;
	return true;
}
bool noIce() //한번에 전부 녹아버리는 케이스 발생가능
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) 
			if (A[i][j]) return true;
	return false;
}
void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++) {
		int py = y+dy[i], px = x + dx[i];
		if (A[py][px] && !visited[py][px] && isRange(py, px)) {
			visited[py][px] = true; 
			dfs(py,px);
		}
	}
	return;
}
bool checkAns()
{
	int cntIce = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j] && A[i][j]) {
				visited[i][j] = true; 
				++cntIce;
				if (cntIce >= 2) return true;
				dfs(i, j);
			}
		}
	}
	return false;
}
void checkIce(int y, int x)
{
	int py, px;
	for (int i = 0; i < 4; i++) {
		py = y + dy[i], px = x + dx[i];
		if (!A[py][px] && isRange(py, px)) {
			q.push({ y,x });
		}
	}
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	int ans = 0;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) {
			scanf("%d", &A[i][j]);
		}
	bool isAns = false;
	while (1) {
		bool isPossible = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (A[i][j]) {
					checkIce(i, j);
				}
			}
		}
		while (!q.empty()) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			if (A[y][x] == 0) isPossible = true;
			else --A[y][x];
		}
		if (isPossible) isAns = checkAns();
		++ans;
		if (!noIce()) {
			ans = 0; break; //빙산이 다 녹을때까지 한덩어리면.
		}
		if (isAns) break; //두개 이상 덩어리 발생
		for (int i = 1; i <= N; i++) 
			memset(visited[i], 0, sizeof(int)*(M + 1));
	}

	printf("%d\n", ans);
	return 0;
}