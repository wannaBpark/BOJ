#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;

int N=0;
vector<int> v;
int D[100010][5][5]={0,};

int cost(int prev, int cur) {
    if (prev == 0) return 2;
    else if (prev == cur) return 1;
    else if (abs(cur-prev) == 2) return 4;
    else return 3; // 그외 인접한 지역 = 힘 3
}
int dp(int i, int l, int r) {
    if (i == N) return 0;
    int& ret = D[i][l][r];
    if (ret) return ret;
    
    ret = INF;
    int costLeft = cost(l, v[i]);           // v[i]로 왼발을 움직일 때의 cost
    int costRight = cost(r, v[i]);          // v[i]로 오른발을 움직일 때의 cost
    // 현재 오른발 위치가 v[i]와 다를때, 왼발을 v[i]로 움직인다.
    if (v[i] != r) ret = min(ret, dp(i+1, v[i], r) + costLeft);
    // 현재 왼발 위치가 v[i]가 아닐 때, 오른발을 v[i]로 움직인다
    if (v[i] != l) ret = min(ret, dp(i+1, l, v[i]) + costRight);

    return ret;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    
    int a;
    while(true) {
        cin >> a;
        if (a==0) break;
        v.push_back(a);
    }
    N = v.size();
    cout << dp(0, 0, 0);
    
    return 0;
}