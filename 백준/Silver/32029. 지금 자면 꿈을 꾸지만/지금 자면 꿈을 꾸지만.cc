#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int ans = 0;
int N,A,B;
int T[110];
void solve();

int main ()
{
    
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    cin>>N>>A>>B;
    for(int i = 0; i < N; ++i) {
        cin >> T[i]; 
    }
    sort(T, T+N);
    solve();
    cout << ans;
    return 0;
}
void solve()
{
    int cnt = 0;
    int curA = A;
    int time = 0;
    for (int i = 0; i < N; ++i) {
        for (int X = 0; X <= A-1; ++X) {
            int sleep = B*X;
            int t = time + sleep;
            curA = A - X;
            
            int sum = 0;
            for (int j = i; j < N; ++j) {
                if (T[j] >= t + curA) {
                    sum++;
                    t += curA;
                }
            }
            ans = max(ans, cnt + sum);
        }
        if (A <= (T[i] - time)) {
            cnt += 1;
            time += A;    
        }
    }
    
}