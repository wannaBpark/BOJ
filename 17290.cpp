#include <cstdio>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;
char A[12][12];
int visited[12][12];
int r, c;
int chkRow[12],chkCol[12];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int> > q;
void bfs(int r, int c, int cnt)
{
	if (!chkRow[r] && !chkCol[c]) {
		printf("%d\n", cnt);
		exit(0);
	}
	for (int i = 0; i < 4; i++) {
		printf("%d %d %d\n", dx[i], dy[i],i);
		int x = r + dx[i];
		int y = c + dy[i];
		if (y >= 0 && y < 10 && x >= 0 && x < 10) {
			bfs(x, y, cnt + 1);
		}
	}
}
int main()
{
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &r, &c);
	for (int i = 0; i < 10; i++) scanf("%s", &A[i]);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (A[i][j] == 'o') chkRow[i] = true, chkCol[j] = true;
		}
	q.push({ r - 1,c - 1 });
	int cnt=0,x,y;
	visited[r - 1][c - 1] = 1;
	while (!q.empty()) {
		int curY = q.front().first, curX = q.front().second;
		if (!chkRow[curY] && !chkCol[curX]) {
			/*printf("%d %d %d\n", curX,curY,cnt);
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					printf("%d ", visited[i][j]);
				}
				puts("");
			}*/
			printf("%d\n", visited[curY][curX]-1);  return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			y = curY + dy[i], x = curX + dx[i];

			if (y >= 0 && y < 10 && x >= 0 && x < 10 && !visited[y][x]) {
				//printf("%d %d %d\n", y, x, cnt);
				visited[y][x] = visited[curY][curX] + 1;
				q.push({ y,x });
			}
		}
		//printf("\n\n");
		cnt++;
	}
	return 0;
}