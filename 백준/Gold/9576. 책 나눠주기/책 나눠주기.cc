#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using pii = pair<int,int>;

int T;
int N, M, ans = 0, A[1010];
bool ch[1010];
std::vector<pii> E;

bool DFS(int n)
{
	ch[n] = true;
	for (int k = E[n].first; k <= E[n].second; ++k) {
		if (!A[k] || (!ch[A[k]] && DFS(A[k])) ) {
			A[k] = n;
			return true;
		}
	}
	return false;
}

int main()
{
    fastio;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        E.push_back({0,0});
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            E.push_back({a,b});
        }

        
        for (int i = 1; i <= M; ++i) {
		    memset(ch, false, sizeof(ch));
		    if (DFS(i)) ++ans;
	    }
        
	    cout << ans << endl;

        E.clear();
        memset(A, false, sizeof(int) * 1002);
        memset(ch, false, sizeof(ch));
        ans = 0;
    }
	
	return 0;
}