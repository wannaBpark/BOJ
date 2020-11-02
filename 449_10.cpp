#include <cstdio>
#include <cstring>
#include <math.h>
//가장 가까운 편의시설까지의 거리와 가장 먼 편의시설까지의 거리의 평균이 최소
int N;
double min = 10000 * sqrt(2);
double max = 0;
int min_index, max_index;
int A[1005][3];
double D[1005];
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &A[i][0], &A[i][1]);
		D[i] = sqrt(pow(A[i][0], 2) + pow(A[i][1], 2));
		if (min > D[i]) {
			min = D[i]; min_index = i;
		}
		if (max < D[i]) {
			max = D[i]; max_index = i;
		}
	}
	return 0;
}