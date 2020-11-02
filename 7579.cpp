#include <cstdio>
#include <cstring>
#define MAX(a,b) (a>b) ? a : b
#define MIN(a,b) (a>b) ? b : a
#define COST 1
#define MEM 0
#define ll long long
#define MAX_COST 10000
int N, M;
int DP[10001] = { 0, };
int Mem[101] = { 0, };
int C[101] = { 0, };
using namespace std;
int knapsack(int pos, int memory, int cost)
{
	if (/*memory - Mem[pos] < 0 || */pos >= N) return MAX_COST;
	else if (memory - Mem[pos] <= 0) return (cost + C[pos]);
	int ret = MIN( knapsack(pos + 1, memory - Mem[pos], cost + C[pos]),
	knapsack(pos + 1, memory, cost) );
	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	//memset(DP, -1, sizeof(DP));
	int totCost=0,i;
	for (int i = 0; i < N; i++)
		scanf("%d", &Mem[i]);
	for (int i = 0; i < N; i++) {
		scanf("%d", &C[i]);
		totCost += C[i];
		//printf("%d\n", C[i]);
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (Mem[i] > Mem[j]) {
				swap(Mem[i], Mem[j]);
				swap(C[i], C[j]);
			}
		}
	}*/
	for (int i = 0; i < N; i++) {
		for (int j = totCost; j >=C[i]; j--) {
			DP[j] = MAX(DP[j], DP[j - C[i]] + Mem[i]);
		}
	}

	for (i = 0; i < totCost && !(DP[i] >= M); i++);
	printf("%d\n", i);
	//printf("%d\n", knapsack(0, M, 0));
	return 0;
}