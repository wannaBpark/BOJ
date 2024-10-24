#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N,M,T;
int A[1010];
int B[1010];
ll pSum1[1010];
ll pSum2[1010];
// map<ll, int> m1;
// map<ll, int> m2;
vector<ll> v1;
vector<ll> v2;
void input() {
    cin >> N;
    for (int i =1; i<=N; ++i) {
        cin >> A[i];
        pSum1[i] = pSum1[i-1] + A[i];
    }
    cin >> M;
    for (int i =1; i<=M; ++i) {
        cin >> B[i];
        pSum2[i] = pSum2[i-1] + B[i];
    }
}
void makebarray() {
    for (int i =0; i<N; ++i){
        for (int j = i+1; j<=N; ++j) {
            ll diff = pSum1[j] - pSum1[i];
            v1.push_back(diff);
            // m1[diff]++;
        }
    }
    sort(v1.begin(), v1.end());
    for (int i =0; i<M; ++i){
        for (int j = i+1; j<=M; ++j) {
            // cout << "i, j, pSum " << i << " " << j << " " << pSum2[j] - pSum2[i]<<'\n';
            ll diff =pSum2[j] - pSum2[i];
            v2.push_back(pSum2[j] - pSum2[i]);
            // m2[diff]++;
        }
    }
    sort(v2.begin(), v2.end());

    // for (auto a:v1) {
    //     printf("%d ", a);
    // } puts("");
    // for (auto a:v2) {
    //     printf("%d ", a);
    // } puts("");
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> T;
    pSum1[0] = pSum2[0] = 0;
    input();
    makebarray();
    
    // v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
    // v2.resize(unique(v2.begin(), v2.end()) - v2.begin());

    ll ans = 0;
    for (int i = 0; i<v1.size(); ) {
        auto& b1 = v1[i];
        ll rest = (ll)T - b1;
        auto idx = lower_bound(v2.begin(), v2.end(), rest);
        
        if (v2[idx - v2.begin()] == rest) {
            ll cnt2 = upper_bound(v2.begin(), v2.end(), rest) - idx;
            ll cnt1 = upper_bound(v1.begin(), v1.end(), b1) - v1.begin() - i;
            ans += cnt1 * cnt2;
            i+= cnt1;

            // printf("cnt1 cnt2 %d %d i:%d b1:%d\n",cnt1,cnt2,i,b1);
        } else {
            ++i;
        }
        // auto idx = lower_bound(v2.begin(), v2.end(), rest) - v2.begin();
        // if (v2[idx] == rest) ++ans;
    }

    cout << ans;
    
    return 0;
}