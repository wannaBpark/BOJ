#include <bits/stdc++.h>
using namespace std;
using ll = long long;

size_t cnt[10010]={0,};
size_t n;

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        int a;
        cin >> a;
        
        cnt[a]++;
    }
    for (size_t i = 1; i <= 10000; ++i) {
        if (cnt[i] != 0) {
            for (size_t j = 0; j < cnt[i]; ++j) {
                cout<< i << '\n';
            }
        }
    } 
    return 0;
}