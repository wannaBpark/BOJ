#include <cstdio>
#include <algorithm>
#define MAX_N 1000000
using namespace std;
int N,index;
int A[MAX_N] = { 0, };
int M[MAX_N] = { 0, };
void dc(int s, int e)
{
	int mid = (s + e) / 2;
	int i = s, j = mid+1;
	if ((e - s) == 1) {
		if (A[s] > A[e]) { swap(A[s], A[e]); M[s] = A[s]; M[e] = A[e]; }
		return;
	}
	else if ((e - s) <= 0) return;
	dc(s, mid);
	dc(mid + 1, e);
	index = s;
	while (!(i>mid && j>e)) {
		//printf("%d %d %d %d %d ", i, j, mid,A[i], A[j]);
		if (i > mid) M[index++] = A[j++];
		else if (j > e ) M[index++]= A[i++];
		else if (A[i] < A[j]) M[index++] = A[i++];
		else M[index++] = A[j++];
		//printf("%d \n", M[index - 1]);
	}
	for (int i = s; i <= e; i++)
		A[i] = M[i];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	dc(0, N-1);
	for (int i = 0; i < N; i++)
		printf("%d\n", A[i]);
	return 0;
}