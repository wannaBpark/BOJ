#include <bits/stdc++.h>
#define MX_N 310
#define MX_K 1e5
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

int Fenwick_Tree[250020];

int MX_INPUT = -1;
int median;
int M, N, K, W;
int arr[250010];
ll ans = 0;

int Sum(int idx)
{
    ll res = 0;
    while (idx > 0) {
        res = res + Fenwick_Tree[idx];
        idx = idx - (idx & -idx);
    }
    return res;
}

void Update(int Idx, int Value)
{
    while (Idx <= 250010) {
        Fenwick_Tree[Idx] = Fenwick_Tree[Idx] + Value;
        Idx = Idx + (Idx & -Idx);
    }
}

inline int bsearch()
{
    int lo = 1;
    int hi = 250010;
    int best = MX_K;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int res = Sum(mid);
        if (res >= median) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return best;
}

// 0 ~ K 까지 범위 유의
int main()
{
    fastio;
    cin >> N >> K;

    median = (K + 1) / 2;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> arr[i];
        ++arr[i];
        Update(arr[i], 1);

        if (i < K - 1) continue;
        ans += bsearch() - 1;
        Update(arr[i - K + 1], -1);
    }

    cout << ans << endl;

    return 0;
}