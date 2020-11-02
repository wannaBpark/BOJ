#include <stdio.h>
#define MAX_N 128
int N;
int cnt[2] = { 0, };
int A[MAX_N][MAX_N] = { 0, };
void dc(int n, int x, int y)
{
	bool isConstant=true;
	int a = A[x][y];
	for (int i = 0; i < n && isConstant; i++) {
		for (int j = 0; j < n; j++) {
			if (a != A[x + i][y + j]){
				isConstant = false;
				break;
			}
		}
	}
	if (isConstant) {
		++cnt[a];
		return;
	}
	dc(n / 2, x, y);
	dc(n / 2, x, y + n / 2);
	dc(n / 2, x + n / 2, y);
	dc(n / 2, x + n / 2, y + n / 2);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		for(int j=0; j< N; j++)
			scanf("%d", &A[i][j]);
	dc(N, 0, 0);
	printf("%d\n%d\n", cnt[0], cnt[1]);
	return 0;
}