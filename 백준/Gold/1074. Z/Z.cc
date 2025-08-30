#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, r,c;
int ans =0;
void divide(int r, int c, int N)
{
    int tmp = pow(N, 2) / 4;
    int x,y;
    x = y = N/2;

    if (r + 1 <= y && c+1 <= x) {
        ans += tmp * 0;
        if (tmp == 1) return;
        divide(r, c, N/2);
    }

    if (r + 1 <= y && c+1 > x) {
        ans += tmp * 1;
        if (tmp == 1) return;
        divide(r, c-x, N/2);
    }

    if (r + 1 > y && c+1 <= x) {
        ans += tmp * 2;
        if (tmp == 1) return;
        divide(r-y, c, N/2);
    }

    if (r + 1 > y && c+1 > x) {
        ans += tmp * 3;
        if (tmp == 1) return;
        divide(r-x, c-x, N/2);
    }    
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> r >> c;
    N = pow(2,N);
    divide(r, c, N);
    cout << ans;
    return 0;
}