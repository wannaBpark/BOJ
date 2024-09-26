#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int N, M;
int p[500010];
int Rank[500010];
int a,b;
int ans = 0;

int find(int a) {
    while (a != p[a])
        a = p[a];
    return a;
}
void solve()
{
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2) {
        ans = true;
        return;
    }
    if (Rank[p1] > Rank[p2]) swap(p1,p2);
    p[p1] = p2;
    if (Rank[p1] == Rank[p2]) ++Rank[p2];
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        p[i] = i;
        Rank[i] = 1;
    }
    for (int i = 1; i <= M; ++i) {
        cin >> a >> b;
        ++a; ++b;
        solve();
        if (ans != 0) {
            cout << i;
            return 0;
        }
    }
    cout << ans;
    return 0;
}