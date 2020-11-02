#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int A[10][10];
int N;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	int a, b;
	for(int i=1; i<=N; i++) {
		scanf("%d%d", &a, &b);
		if (b == 0) {
			A[i][b] = 1; //b가 1루수이다
		}
		else {
			A[i][b] = 2; //b는 1루수 아니다.
		}
	}
	return 0;
}