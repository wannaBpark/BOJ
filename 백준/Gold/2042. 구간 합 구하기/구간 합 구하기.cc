#include <bits/stdc++.h>
#define MX_N 2000010
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

ll Fenwick_Tree[MX_N];
ll arr[MX_N];
int M, N, K;


ll Sum(int idx)
{
    ll res = 0;
    while (idx > 0) {
        res = res + Fenwick_Tree[idx];
        idx = idx - (idx & -idx);
    }
    return res;
}

void Update(int Idx, ll Value)
{
    while (Idx <= N) {
        Fenwick_Tree[Idx] = Fenwick_Tree[Idx] + Value;
        Idx = Idx + (Idx & -Idx);
    }
}

// 0 ~ K 까지 범위 유의
int main()
{
    fastio;
    cout.tie(NULL);
    cin >> N >> M >> K;

    int query_cnt = M + K;
    ll prev = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        Update(i, arr[i]);
        prev = arr[i];
    }

    int a, b;
    ll c;
    while (query_cnt--) {
        cin >> a >> b >> c;

        if (a == 1) {
            Update(b, c - arr[b]);
            arr[b] = c;
        } else if (a == 2) {
            cout << Sum(c) - Sum(b - 1) << '\n';
        }
    }

    return 0;
}