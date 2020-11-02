#include <cstdio>
#include <algorithm>
using namespace std;
int A[500001];
int bsearch(int start, int end, int k)
{
	int mid = (start + end) / 2;
	if (start > end) return 0;
	if (A[mid] == k) return 1;
	else if (A[mid] < k)
		bsearch(mid + 1, end, k);
	else
		bsearch(start, mid - 1, k);
}
int main()
{
	int N, M, a, i = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	while (N--) scanf("%d", &A[i++]);
	sort(A, A + i);
	scanf("%d", &M);
	while (M--) scanf("%d", &a), printf("%d ", bsearch(0, i - 1, a));
	return 0;
}