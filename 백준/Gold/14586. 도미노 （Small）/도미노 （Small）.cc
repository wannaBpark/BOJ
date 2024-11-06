#include <bits/stdc++.h>
#define INF 1e9
#define x first
#define h second
using namespace std;
using ll = long long;

int N;
vector<pair<ll, ll>> v;
int mxleft[310];
int mxright[310];
int D[310];
// dp (i) : i번째 도미노를 왼/오른쪽으로 넘어뜨릴 때 [0,i]구간 총합 모든 도미노를 넘어뜨린 최소 개수
int dp(int i) {
    if (i<0) return 0;
    int& ret = D[i];
    if (ret != INF) return ret;

    int mxl = mxleft[i];
    int mxr = mxright[i];

    ret = min(ret, dp(mxl - 1) + 1);

    // j번째부터 오른쪽으로 넘어뜨렸을때, i번째 도미노까지 넘어지는경우
    // 0번째(j=0)부터 i까지 쭉 넘어뜨리면, 1
    // 맨앞이 아닌 j부터 i까지 넘어뜨리면, dp(j-1) + 1
    for (int j = i-1; j>=0; --j) {
        if (mxright[j] >= i)
            ret = min(ret, (j-1<0 ? 0 : dp(j-1)) + 1);
    }
    return ret;    
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    v.reserve(N);
    for (int i=0; i<N; ++i) {
        ll a,b;
        cin >> a >> b;
        v.push_back({a,b});
        mxleft[i] = mxright[i] = i;
        D[i] = INF;
    }
    sort(v.begin(), v.end());
    for (int i =0; i<N; ++i) {
        ll right = v[i].x + v[i].h;
        ll left = v[i].x - v[i].h;
        for (int j = i+1; j < N && v[j].x <= right; ++j){
            right = max(right, v[j].x + v[j].h);
            mxright[i] = j;
        }
        
        for (int j = i-1; j >= 0 && v[j].x >= left; --j){
            left = min((ll)left, v[j].x - v[j].h);
            mxleft[i] = j;
        }
    }
    D[0] = 1;
    cout << dp(N-1);
    return 0;
}