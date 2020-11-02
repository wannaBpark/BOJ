#include <cstdio>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<int, int> > v;
int main()
{
	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N; i++) scanf("%d%d", &a, &b), v.push_back({b,a });
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) printf("%d %d\n", v[i].first, v[i].second);
	int end = v[0].first, start = v[0].second;
	
	int ans = 1;
	for (int i = 1; i < N; i++) {
		int nx = v[i].second;
		if (nx >= end) {
			end = v[i].first, ++ans;
			printf("change : %d %d\n", v[i].second, v[i].first);
		}
	}
	printf("%d\n", ans);
	return 0;
}