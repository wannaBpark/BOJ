#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int water[510];
int H,W;
int total = 0;
int solve(int cur) {
    int left = cur;
    int right = cur;
    int mxLeft = water[cur];
    int mxRight = water[cur];
    while (left >= 0) {
        if (water[left] >= mxLeft) mxLeft = water[left];
        --left;
    }
    while (right < W) {
        if (water[right] >= mxRight) mxRight = water[right];
        ++right;
    }
    int ret = min(mxRight, mxLeft) - water[cur];
    if (left < cur && right > cur) {
        return ret < 0 ? 0 : ret;
    } else {
        return 0;
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >>H >> W;
    for (int i =0; i<W; ++i) {
        cin >> water[i];
    }
    for (int i = 1; i<W-1; ++i) {
        total += solve(i);
    }
    cout << total;
    return 0;
}