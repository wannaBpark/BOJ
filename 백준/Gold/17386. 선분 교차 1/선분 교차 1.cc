#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using ll = long long;
using Point = pair<ll,ll>;

//시계 방향이면 음수, 반시계면 양수, 일직선상은 0
int CCW(const Point& p1, const Point& p2, const Point& p3)
{
    ll res = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    res -= p2.x*p1.y + p3.x*p2.y + p1.x*p3.y;
    return (res > 0) - (res < 0);
    
}
bool Cross(Point a, Point b, Point c, Point d)
{
    int ab = CCW(a,b,c) * CCW(a,b,d);
    int cd = CCW(c,d,a) * CCW(c,d,b);
    // 일직선상에 있을 때
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a,b);
        if (c > d) swap(c,d);
        //제일큰 b가 cd시작점 c보다 작거나,
        // 제일 작은 a가 제일큰 d보다 크다면 교차 X
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1 >> y1 >> x2 >> y2;
    cin>>x3 >> y3 >> x4 >> y4;
    cout<<Cross({x1,y1},{x2,y2},{x3,y3},{x4,y4})<< endl;
    
    return 0;
}