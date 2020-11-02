#include <stdio.h>
#include <stdio.h>
#define MAX_N 2187
int N;
int cnt[3] = { 0, };
int A[MAX_N][MAX_N] = { 0, };
void dc(int n, int x, int y)
{
	int i, j;
	bool isConstant = true;
	int a = A[x][y];
	for (i = 0; i < n && isConstant; i++) {
		for (j = 0; j < n; j++) {
			if (a != A[x + i][y + j]) {
				isConstant = false;
				break;
			}
		}
	}
	if (isConstant) {
		++cnt[a+1];
		return;
	}
	/*if (n == 3) {
		for (i = 0; i < n; i += (n / 3))
			for (j = 0; j < n; j += (n / 3))
				++cnt[A[x + i][y + j] + 1];
		return;
	}*/ //Q.계산횟수는 똑같은가?
	for (i = 0; i < n; i += (n / 3))
		for (j = 0; j < n; j += (n / 3))
			dc(n / 3, x+i, y+j);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j< N; j++)
			scanf("%d", &A[i][j]);
	dc(N, 0, 0);
	printf("%d\n%d\n%d\n", cnt[0], cnt[1],cnt[2]);
	return 0;
}