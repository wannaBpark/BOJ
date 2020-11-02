#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
int cnt[12], A[1001000];
int M, N,tmp;
int q(int a)
{
	if (a >= 1 && a <= 9) return 1;
	if (a >= 10 && a <= 99) return 2;
	if (a >= 100 && a <= 999) return 3;
	if (a >= 1000 && a <= 9999) return 4;
	if (a >= 10000 && a <= 99999) return 5;
	if (a >= 100000 && a <= 999999) return 6;
}
int main()
{
	scanf("%d%d", &N, &M);
	int t1, t2, i;
	int jarisoo, sum;
	for (int i = 0; i < M; i++)scanf("%d", &tmp), cnt[tmp]++;
	for (int i = 0; i <= 999999; i++) {
		A[i] = abs(i - 100);
		int tmp = i; bool isUpdate = true;
		if (tmp == 0) {
			if (!cnt[0]) A[i] = 1;
			continue;
		}
		while (tmp != 0) {
			if (cnt[tmp % 10]) {
				isUpdate = false;
				break;
			}
			tmp /= 10;
		}
		if (isUpdate) {
			A[i] = min(q(i), A[i]);
		}
	}
	for (int i = 0; i <= 999999; i++) {
		if(N+i<=999999) A[N] = min(A[N], A[N + i] + abs(i));
		if(N-i >=0) A[N] = min(A[N], A[N - i] + abs(i));
	}
	printf("%d\n", A[N]);
	/*if (N == 100) {
		puts("0"); return 0;
	}
	for (i = 0; i <= 500000; i++) {
		t1 = N + i;
		sum = 0;
		bool isAns = true;
		while (t1!=0) {
			jarisoo = t1 % 10;
			if (cnt[jarisoo]) {
				isAns = false;
				break;
			}
			t1 = t1 / 10;
			sum++;
		}
		if (isAns) {
			printf("%d\n", min((sum + i),abs(N-100))); return 0;
		}
		if (t1 == 0 && !cnt[t1]) {
			if (N == 0) puts("1");
			else printf("%d\n", min((1 + i), abs(N - 100)));
			return 0;
		}

		if (t1 == N) continue;
		if (t1 == 0) sum = 1;
		t1 = N - i; sum = 0;
		if (t1 < 0) continue;
		while (t1 != 0) {
			jarisoo = t1 % 10;
			if (cnt[jarisoo]) {
				isAns = false;
				break;
			}
			t1 = t1 / 10;
			sum++;
		}
		if (isAns) {
			printf("%d\n", min((sum + i), abs(N - 100)));
			return 0;
		}
		if (t1 == 0 && !cnt[t1]) {
			if (N == 0) puts("1");
			else printf("%d\n", min((1 + i), abs(N - 100)));
			return 0;
		}
	}
	printf("%d\n", abs(N - 100));*/
	return 0;
}