#include <cstdio>
#include <cstring>
#define max(a,b) { (a>b) ? a: b}
int R, C,ans=0;
char pick[500];
char B[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int chk(char pick[], char C, int sum)
{
	for (int i = 1; i <=sum; i++)
		if (pick[i] == C) return 0;
	return 1;
}
void dfs(int x, int y, int sum)
{	
	//printf("%d %d %d\n", x, y, sum);
	pick[sum] = B[x][y];
	ans = max(sum, ans);
	int px, py;
	bool isEnd = true;
	for (int i = 0; i < 4; i++) {
		px = dx[i] + x; py = dy[i] + y;
		if (px < 0 || py < 0 || px >= R || py >= C) continue;
		if (chk(pick, B[px][py],sum)) {
			//printf("%d %d에서 %d %d로 출발")
			dfs(px, py, sum + 1);
		}
	}
	return;
	//더이상 갈수없으면 return sum
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) scanf("%s", &B[i]);
	//printf("%d\n", dfs(0, 0,1));
	dfs(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}