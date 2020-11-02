#include <cstdio>
#include <algorithm>
#define MAX_N 5000000
using namespace std;
int N, index, K;
int A[MAX_N] = { 0, };
int Partition(int left, int right)
{
	int pivot = A[left];
	int i = left + 1, j = right;
	while (i <= j) {
		while (A[i] <= pivot && i <= right) i++;
		while (A[j] >= pivot && j >= (left+1)) j--;
		if (i <= j) swap(A[i], A[j]);
	}
	/*for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("j= %d\n", j);*/
	swap(A[left], A[j]);
	
	return j;
}
int quickSelect(int left, int right)
{
	int nth = Partition(left, right);
	if (nth == K) return A[nth];
	else if (nth < K) Partition(nth + 1, right); // 0 1 2 3 4
											     // 1 2 3 4 5	2
	else if (nth > K) Partition(left, nth - 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	printf("%d\n", quickSelect(0,N-1));
	/*for (int i = 0; i < N; i++)
		printf("%d ", A[i]);*/
	return 0;
}