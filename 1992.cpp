#include <cstdio>
int N;
char A[65][65];
void dc(int y, int x, int s)
{
	//printf("%d %d %d\n", y, x, s);
	int cnt = 0;
	for (int i = y; i < y+s; i++) {
		for (int j = x; j < x+s; j++) {
			cnt += (A[i][j] - '0');
			//printf("%d ", A[i][j]);
		}
		//puts("");
	}
	//printf("%d\n", cnt);
	if (cnt == s*s) {
		//printf("%d %d %d\n", y, x, s);
		printf("1"); return;
	}
	else if (cnt == 0) {
		printf("0"); return;
	}
	else {
		s /= 2;
		printf("(");
		dc(y,x,s); dc(y,x+s,s);
		dc(y+s,x,s); dc(y+s,x+s,s);
		printf(")");
		return;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	//printf("%d\n", N);
	for (int i = 0; i < N; i++) scanf("%s", &A[i]);
	dc(0, 0, N);
	return 0;
}