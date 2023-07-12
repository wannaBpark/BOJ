#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using Point = pair<ll, ll>;
vector<Point> v;
int N;

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
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}
vector<Point> ConvexHullAndrew()
{
    // stack that represents Sets of points represents Convex Hull
    vector<Point> s;
    vector<Point> points = v;
    int k = s.size();

    for (int i = 0; i < N;) {
        k = s.size();
        Point p3 = points[i];
        // 아직 아무것도 고르지 않았거나, 반시계 방향일 때 추가 (일직선일때에는 현재 stack의 맨 뒷원소를 빼버린다
        if (k < 2 || CCW(s[k - 2], s[k - 1], p3) < 0) {
            s.push_back(p3);
            ++i;
        } else {
            s.pop_back();
        }
    }

    s.push_back(points[N - 2]);
    for (int i = N - 1; i >= 0;) {
        k = s.size();
        Point p3 = points[i];

        if (s[k - 1] == points[N - 1] || CCW(s[k - 2], s[k - 1], p3) < 0) {
            s.push_back(p3);
            --i;
        } else {
            s.pop_back();
        }
    }
    s.pop_back();
    s.pop_back();
    return s;
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
    sort(v.begin(), v.end());
    vector<Point> v_ans = ConvexHullAndrew();
    cout << v_ans.size();

    return 0;
}