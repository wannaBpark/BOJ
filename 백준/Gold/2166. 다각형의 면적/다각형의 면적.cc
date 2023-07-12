#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using Point = pair<ll,ll>;

vector<Point> v;
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    ll x1,y1,sum = 0;
    ld cx = 0, cy = 0, ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x1 >> y1;
        v.push_back({x1,y1});
    } 
    cx = v[0].x; cy = v[0].y;
    
    for (int i =0; i < N; ++i) {
        int j = i == N -1  ? 0 : i+1;
        sum += (v[i].x * v[j].y) - (v[i].y * v[j].x);
        // 외적으로 평행사변형 넓이 구하기
    }
    sum = abs(sum);
    ans = (ld)sum / (ld)2.f;
    // 삼각형들로 바꾸기 위해 나누기 2
    cout << fixed << setprecision(1) << ans;
    return 0;
}