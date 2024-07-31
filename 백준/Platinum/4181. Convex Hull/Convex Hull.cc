#include <bits/stdc++.h>
#define x first 
#define y second

using namespace std;
using ll=long long;
ll ans = 0;
int N;
void solve();

using Point = pair<ll, ll>;

vector<Point> v;
vector<Point> v_ans;

ll CCW(const Point& p1, const Point& p2, const Point& p3)
{
    ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    res -= p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;
    return res;
    // return (res > 0) - (res < 0);
}

bool compXY(const Point& p1, const Point& p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

bool compare(const Point& p1, const Point& p2) {
    ll ccwVal = CCW(v[0], p1, p2);

    if (ccwVal == 0) { // 동일선상에 위치
        if (p1.x == p2.x) return p1.y > p2.y;
        else {
            if (p1.y == p2.y) return p1.x < p2.x;
            else return p1.y > p2.y;
            // 우상단 대각선일 때, 우상단 좌표를 먼저 오도록
        }
    }
    else {
        return ccwVal > 0; // p1, p2가 반시계 방향 이루도록
    }
}

int main ()
{
    
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N;
    for (int i =0; i <N; ++i) {
        ll a,b; char c;
        cin >> a >> b >>c;
        if (c == 'Y') {
            v.push_back({a,b});
        }
    }
    sort(v.begin(), v.end(), compXY);
    sort(v.begin() + 1, v.end(), compare);

    v_ans.push_back(v[0]);
    v_ans.push_back(v[1]);

    for (int i = 2; i < v.size(); ++i) {
        while (v_ans.size() >= 2) {
            Point p1 = v_ans.back();
            v_ans.pop_back();
            Point p2 = v_ans.back();

            ll ccwVal = CCW(v[i], p1, p2);
            if (ccwVal <= 0) {
                v_ans.push_back(p1);
                break;
            }
        }
        v_ans.push_back(v[i]);
    }

    cout << v_ans.size() << '\n';
    for (auto p : v_ans) {
        cout << p.x << " " << p.y << '\n';
    }
    return 0;
}