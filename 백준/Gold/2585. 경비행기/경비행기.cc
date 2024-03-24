#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> v;
int visited[1010] ={0,};
double dist[1010][1010];

int DFS(int idx, int fuel);
void CalculateDist();

int fuel;
int n, k;

static inline double squaredSum(pair<int, int>& p1, pair<int, int>& p2){
    auto& a = p1.first; auto& b = p1.second;
    auto& c = p2.first; auto& d = p2.second;
    double x = a - c;
    double y = b - d;

    auto res = x*x + y*y;
    return res;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); 
    cin >> n >> k;

    v.push_back({0,0});
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }    
    v.push_back({10000,10000});
    
    CalculateDist();

    int l = 1, r = 14143; // root(2*1e8) = root(2) * 1e4
    while (l <= r) {
        int mid = (l + r) / 2;
        fuel = mid * mid * 10 * 10; // [fuel] * 100 = distance
        memset(visited, false, sizeof(visited));

        int res = DFS(0, 0);
        if (res == true) { 
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;

    return 0;
}

int DFS(int cur, int cnt)
{
    // queue<pair<int, int>> q;
    if (dist[cur][n + 1] <= fuel) return true; // True if Destination reachable
    if (cnt > k) return false;

    visited[cur] = true;

    for (int i = 1; i <= n; ++i) {
        if (visited[i] == true) continue; // Already visited
        if (dist[cur][i] > fuel) continue;

        if (DFS(i, cnt + 1))
            return true; // if stopover available and Destination Reachable, return true
    }

    return false;
}

void CalculateDist()
{
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n + 1; ++j) {
            if (i == j) dist[i][j] = 1e9;
            else dist[i][j] = dist[j][i] = squaredSum(v[i],v[j]);
        }
    }
}