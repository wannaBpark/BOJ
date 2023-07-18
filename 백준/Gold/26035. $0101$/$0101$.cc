#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define x first
#define y second
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<ll,ll>;

const ll mod = 1e9+7;
ll n, m, res;

ll f(ll x, ll e)
{
    if(e == 0){
        return 1;
    }
    if(e&1){
        return (x*f(x, e-1))%mod;
    }
    else{
        ll t = f(x, e/2);
        return (t*t)%mod;
    }
}

int main(){
    scanf("%lld %lld", &n, &m);
    res  = f(2, m) + f(2, n) - 2;
    printf("%lld", (res+mod)%mod);
}