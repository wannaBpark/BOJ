#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int>> q;
pair<int, int> cur;
int N, M;
int Day[1000][1000] = { 0 },ans;
int A[1000][1000];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int isRange(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return 0;
	return 1;
}
bool isRipen()
{
	bool isRipen = true;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j] == 0) return false;
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j] == 1) q.push({ i,j });
		}
	/*if (isRipen) {
		printf("0\n"); return 0; 어차피 이미 다 익어있으면 ans처리가 된다.
	}*/
	int x, y,px,py;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		ans = A[x][y];
		for (int i = 0; i < 4; i++) {
			px = x + dx[i], py = y + dy[i];
			if (isRange(px, py) && A[px][py] == 0) {
				q.push({ px,py });
				A[px][py] = A[x][y] + 1;
			}
		}
	}
	isRipen() ?  printf("%d\n", ans-1): printf("-1\n");
	return 0;
}