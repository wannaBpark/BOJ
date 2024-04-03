#include <bits/stdc++.h>
#define MXN 100
using namespace std;
using ll = long long;
int N;
string A;
int input[MXN];
int ans = INT_MIN;
int cal(int l, int r, int op)
{
    int res;
    switch (op) {
    case '+': res = l + r; break;
    case '-': res = l - r; break;
    case '*': res = l * r; break;
    }
    return res;
}
void dfs(size_t idx, int cur)
{
    size_t i = idx;
    // printf("%d %d, cur point: %d\n", idx, cur, input[idx]);
    int op = (i == 0) ? '+' : input[idx - 1];
    if (idx > N-1) {
        ans = max(ans, cur);
        return;
    }
    // TO ADD BRACKET
    if (i + 2 < N) {
        int bracket = cal(input[i], input[i+2], input[i+1]);
        dfs(i+4, cal(cur, bracket, op));
    }
    // NOT TO ADD BRACKET
    dfs(i+2,cal(cur, input[idx], op));
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> N >> A;
    for (size_t i=0; i < N; ++i) {
        if (A[i] >= '0' && A[i] <= '9') {
            input[i] = A[i] - '0';
        } else {
            input[i] = A[i];
        }
    }

    dfs(0, 0);
    cout << ans;
    return 0;
}