#include <bits/stdc++.h>
#define MX_N 1000010
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;
using ld = long double;

ll Fenwick_Tree[MX_N];
ll Fenwick_Tree_Zero[MX_N];
int M, N, K, W;
ll arr[MX_N];
const ll MOD = 1000000007;
ll Multiply(int idx)
{
    ll res = 1;
    while (idx > 0) {
        res = (res * Fenwick_Tree[idx]) % MOD;
        idx -= (idx & -idx);
    }
    return res;
}

void Update(int Idx, ll Value)
{
    while (Idx <= N) {
        Fenwick_Tree[Idx] = (Fenwick_Tree[Idx] * Value) % MOD;
        Idx = Idx + (Idx & -Idx);
    }
}

ll Sum(int idx) 
{
    ll res = 0;
    while (idx > 0) {
        res += Fenwick_Tree_Zero[idx];
        idx = idx - (idx & -idx);
    }
    return res;    
}
void UpdateZero(int Idx, ll Value)
{
    while (Idx <= N) {
        Fenwick_Tree_Zero[Idx] += Value;
        Idx += (Idx & -Idx);
    }
}

ll pow(ll a, ll n) { // a의 n승 구하기 
    if (n == 1) return a;

    ll half = pow(a, n / 2);

    if (n % 2 == 0) 
        return half * half % MOD;
    else 
        return (half * half % MOD) * a % MOD;
}

ll modularInverse(ll a) {
    return pow(a, MOD - 2); // MOD and a 가 서로소이기 때문에, a의 모듈러 역원은 a^MOD-2
}




// 0 ~ K 까지 범위 유의
int main()
{
    fastio;
    cout.tie(NULL);
    cin >> N >> M >> K;

    fill(Fenwick_Tree, Fenwick_Tree + N + 1, 1LL);
    int query_cnt = M + K;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        if (arr[i] == 0) { // 0인 경우 0개수 업데이트 및 실제 펜윅트리에는 1저장(무엇을 곱해도 0되지 않게)
            UpdateZero(i, 1LL);
            arr[i] = 1;
        } else {            // 0 아닌 수는 곱 펜윅 트리 업데이트
            Update(i, arr[i]);
        }

        // cout << Fenwick_Tree[i] << " " << endl;
    }

    int a, b;
    ll c;
    while (query_cnt--) {
        cin >> a >> b >> c;
        if (a == 1) {
            if (c == 0) {
                UpdateZero(b, 1LL);
            } else {
                if (Sum(b) != Sum(b - 1)) UpdateZero(b, -1LL);
                Update(b, modularInverse(arr[b]));
                Update(b, c);
                arr[b] = c;
            }
        } else if (a == 2) {
            if (Sum(c) != Sum(b - 1)) 
                cout << "0\n";
            else
                cout << Multiply(c) * modularInverse(Multiply(b - 1)) % MOD << '\n';
        }
    }

    return 0;
}