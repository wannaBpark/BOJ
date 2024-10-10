#include <bits/stdc++.h>
using namespace std;
int N;
int isUsed(int x, int& used) {
    while (x) {
        int tmp = (1 << (x%10));
        if (tmp & used) {
            return true;
        }
        used = used | tmp;
        x /= 10;
    }
    return false;
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    
    for (int i = 1; i<=87654 && i < N; ++i) {
        int used = 0;
        // cout << i << " " << used << '\n';

        if (isUsed(i, used)) continue;
        if (isUsed(N-i, used)) continue;
        else {
            cout << N-i << " + " << i;
            return 0;
        } 
    }
    cout << "-1";
    return 0;
}