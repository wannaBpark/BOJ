#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 1000000
using namespace std;
int N, M,ans=0;
queue<pair<int,int>> q;
char A[51][51];
int visited[51][51] = { 0 };
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
bool isRange(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	return true;
}
void bfs()
{
	int y, x,cnt=0;
	while (!q.empty()) {
		y = q.front().first, x = q.front().second; q.pop();
		cnt = visited[y][x];
		for (int i = 0; i < 4; i++) {
			int py = y + dy[i], px = x+dx[i];
			if(A[py][px] == 'L' && isRange(py,px) && !visited[py][px]){
				q.push({ py, px }); 
				visited[py][px] = visited[y][x] + 1;
				//printf("py px %d %d %d\n", py, px, visited[py][px]);
			}
		}
	}
	ans = max(cnt, ans);
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N,&M);
	for (int i = 0; i < N; i++) scanf("%s", &A[i]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 'L') {
				q.push({ i,j }); 
				visited[i][j] = true;
				bfs();
				memset(visited, 0, sizeof(visited));
				//fill보다 memset이 시간이 더 적게걸리는듯.
			}
		}
	}
	ans == 0 ? printf("0\n")  : printf("%d\n", ans - 1);
	return 0;
}