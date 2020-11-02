#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
char S[26][26];
int visited[26][26];
vector<int> danji;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;
int index = 0;
int house = 0;
void dfs(int i, int j)
{
	house++; // (i,j)를 들린다 = 집의 개수를 늘린다
	visited[i][j] = true; // (i,j)의 방문 표시
	for (int k = 0; k<4; k++) {
		int x = i + dx[k]; 
		int y = j + dy[k];
		if (x >= 0 && x < N && y >= 0 && y < N && 
			visited[x][y] == 0 && S[x][y] == '1')
			dfs(x, y);
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", S[i]); //입력
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%c", &S[i][j]);
		}
	}*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	} //방문 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (S[i][j] == '1' && visited[i][j] == 0) {
				dfs(i, j); 
				ans += 1;
				danji.push_back(house);
				house = 0;
				index++;
			}

		}
	}
	sort(danji.begin(), danji.end());
	printf("%d\n", ans);
	for (int i = 0; i < danji.size(); i++)
		printf("%d\n", danji[i]);
	return 0;
}