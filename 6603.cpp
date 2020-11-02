#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
int k, maximum;

int N, M, V;
int pick[7];
int A[13];
//int combination(int c, int fac)
//{
//	int tmp = 1;
//	for (int i = 0; i < fac; i++)
//		tmp *= c--;
//	for (int i = 1; i <= fac; i++)
//		tmp /= i;
//	printf("%d\n", tmp);
//	return tmp;
//}

void dfs(int cnt, int lastIndex)
{
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", A[pick[i]]);
		}
		printf("\n");
		return;
	}
	for (int i = lastIndex+1; i < k; i++) {
		pick[cnt] = i; //현재 cnt개까지 골랐고, 그 인덱스를 i로 설정한다.
		dfs(cnt + 1, i); 
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &k);
	while (k) {		
		for (int i = 0; i < k; i++) {
			scanf("%d", &A[i]);
		}
		dfs(0, -1);
		printf("\n");
		scanf("%d", &k);
	}
	
	return 0;
}