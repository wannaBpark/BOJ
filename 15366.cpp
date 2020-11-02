#include<cstdio>
#include <algorithm>
#include<vector>
using namespace std;
int N;
vector<int> w;
vector<int> wB;
bool isPossible = true;
int main()
{
	int a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a),w.emplace_back(a);
	for (int i = 0; i < N; i++) scanf("%d", &a),wB.emplace_back(a);
	sort(w.begin(), w.end());
	sort(wB.begin(), wB.end());
	for (int i = 0; i < N; i++) if (w[i] > wB[i]) { isPossible = false; break; }
	isPossible ? printf("DA\n") : printf("NE\n");
	return 0;
}