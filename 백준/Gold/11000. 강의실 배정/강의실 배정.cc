#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
struct Class{
    int s, t;
};
bool compare(const Class& c1, const Class& c2) {
    if (c1.s == c2.s) {
        return c1.t < c2.t;
    }
    return c1.s<c2.s;
}
int N,ans=1;
vector<Class> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    for (int i =0; i<N; ++i) {
        int s,t;
        cin >> s >> t;
        v.push_back({s,t});
    }    
    // for (int i =0; i<N; ++i) {
    //     cout << v[i].s << " " <<v[i].t << '\n';
    // } 
    // pq : 지금까지 배정한 강의실 중 가장 종료시간이 빠른것 = top()
    // 만일 가장 종료시간이 빠른것보다 시작시간이 작다? 무조건 새 강의실 배정해야함
    // (1)가장 종료시간 빠른 것 <= (2)새 강의 시작시간이라면
    // (1)번이 쓰던 강의실을 (2)에 물려주자

    sort(all(v), compare);
    for (int i =0; i< N; ++i) {
        pq.push(v[i].t);
        if (pq.top() <= v[i].s) pq.pop(); 
    }
    cout << pq.size();
    return 0;
}