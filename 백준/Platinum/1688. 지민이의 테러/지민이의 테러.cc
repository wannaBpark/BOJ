#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using Point = pair<ll, ll>;

vector<Point> v;
vector<Point> friends;
int N;

//시계 방향이면 음수, 반시계면 양수, 일직선상은 0
int CCW(const Point& p1, const Point& p2, const Point& p3)
{
    ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    res -= p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;
    return (res > 0) - (res < 0);
}
bool Cross(Point a, Point b, Point c, Point d)
{
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    // 일직선상에 있을 때
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        //제일큰 b가 cd시작점 c보다 작거나,
        // 제일 작은 a가 제일큰 d보다 크다면 교차 X
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll x, y;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        v.push_back({ x,y });
    }
    for (int i = 0; i < 3; ++i){
        cin >> x >> y;
        // v.push_back({x,y});
        friends.push_back({x,y});
    }
    vector<Point> v_ans = v;
    
    for(auto& cur : friends) {
        Point curEnd = {cur.x + 1e9+10, cur.y + 1};
        ll cnt = 0;
        
        bool canProtect = false;
        for (int i = 0; i < v_ans.size(); ++i){
            int j = i == v_ans.size() - 1 ? 0 : i+1;

            cnt += Cross(v_ans[i], v_ans[j], cur, curEnd);
            int ccw = CCW(v_ans[i], cur, v_ans[j]);

            if (ccw == 0 && (v_ans[i] <= cur && cur <= v_ans[j] || v_ans[j] <= cur && cur <= v_ans[i]) ) {
                canProtect = true;
                break;
            } 
        }
PRINT: 
        // printf("cnt : %lld \n", cnt);
        if (canProtect) cout << canProtect << endl;
        // 교차횟수가 홀수일 때 지켜줄 수 있음 = 다각형 내부에서 Ray를 쏘므로
        else cout << (cnt & 1) << endl;
    }

    return 0;
}