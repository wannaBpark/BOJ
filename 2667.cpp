#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

int N, M, V;
int visited[26][26] = { 0, };
char A[26][26];
int sum[10000];
int index = 1, cnt = 0;

void bfs(int i, int j)
{
	if (visited[i][j] && !(i>=0 && j>=0 && i<N && j<N)) return;
	else if (A[i][j] == '0') return;
	else if (!visited[i][j] && A[i][j] == '1') {
		visited[i][j] = 1;
		++cnt;
		//printf("%d %d\n", i, j);
		bfs(i + 1, j);
		bfs(i - 1, j);
		bfs(i, j + 1);
		bfs(i, j - 1);
	}
	else return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//printf("%c ", A[i][j]);
			if (!visited[i][j] && A[i][j] == '1') {
				bfs(i, j);
				sum[index++] = cnt;
			}
			cnt = 0;
		}
		//printf("\n");
	}
	sort(sum, sum + index);
	if (index == 1) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", index - 1);
	for (int i = 1; i < index; i++)
		printf("%d\n", sum[i]);
	return 0;
}