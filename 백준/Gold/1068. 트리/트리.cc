#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> E[55];
int value[55], child[55], par[55];
int N, p, dlt, ans, root;

void dfs(int cur, int prev)
{
	if(E[cur].size() == 0){ // leaf node
		value[cur] = 1;
		return;
	}
	
	for(int t : E[cur]){
		if(t != prev){
			dfs(t,cur);
			value[cur] += value[t];
		}
	}
	return;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &p);
		
		if(p == -1) root = i;
		
		par[i] = p;
		child[p]++;
		E[p].push_back(i);
	}
	scanf("%d", &dlt);
	dfs(root, -1);
	
	ans = value[root] - value[dlt];
	if(par[dlt] != -1 && child[par[dlt]] == 1) // O-O-O 에서 중간을 자르는 예외처리
		ans++;
	printf("%d", ans);
	return 0;
}