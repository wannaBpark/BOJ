#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Point {
    int x, y;
};
vector<Point> v;
int LIS[510];
int N;
int ans=0;

// i번째 인덱스까지 전봇대 안겹치기 위한 최소 제거 개수
// 제거하고 나면, 모든 y는 오름차순 정렬된, 최대 부분 증가 수열
// N - ans (최대 부분 증가수열의 길이) = 제거할 전깃줄 개수
void solve(int n) {
    for (int i = 1; i < n; ++i) {
        int mx = 0;
        for (int j = 0; j < i; ++j) {
            if (v[j].y < v[i].y) {
                mx = max(mx, LIS[j] + 1);
            }
        }
        LIS[i] = max(LIS[i], mx);
    }
}
bool cmp(Point& p1, Point& p2) {
    return p1.x < p2.x;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i<N; ++i) {
        int a,b;
        cin >> a >> b; 
        v.push_back({a,b});
        LIS[i] = 1;
    }
    sort(v.begin(), v.end(), cmp);
    solve(N);
    for (int i= 0; i<N; ++i) {
        ans = max(LIS[i], ans);
    }
    cout << N - ans;    
    return 0;
}