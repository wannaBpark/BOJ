#include <cstdio>
#include <algorithm>
#include <math.h>
int N, r, c;
int quadrant, ans=0;
void dc(int n, int x, int y)
{
	if (x == r && y == c) {
		printf("%d\n", ans);
		exit(0);
	}
	if (n == 1) {
		ans++; return;
	}
	dc(n / 2, x, y);
	dc(n / 2, x, y + n / 2);
	dc(n / 2, x + n / 2, y);
	dc(n / 2, x + n / 2, y + n / 2);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &r, &c);
	N = pow(2,N);
	r += 1; c += 1;
	if (r > (N / 2) && c > (N / 2)) {
		quadrant = 4;
		ans += pow(N, 2) / 4 * (quadrant - 1);
		dc(N / 2, N / 2 + 1 , N / 2 + 1);
	}
	else if (r > (N / 2) && c <= (N / 2)) {
		quadrant = 3;
		ans += pow(N, 2) / 4 * (quadrant - 1);
		dc(N / 2, N / 2 + 1, 1);
	}
	else if (r <= (N / 2) && c > (N / 2)) {
		quadrant = 2; 
		ans += pow(N, 2) / 4 * (quadrant - 1);
		dc(N / 2, 1, N / 2 + 1);
	}
	else if (r <= (N / 2) && c <= (N / 2)) {
		quadrant = 1;
		ans += pow(N, 2) / 4 * (quadrant - 1);
		dc(N / 2, 1, 1);
	}
	
	return 0;
}