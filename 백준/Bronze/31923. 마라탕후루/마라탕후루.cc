#include <bits/stdc++.h>
#define MAX 10000
using ll = long long;
using namespace std;

int N,P,Q;
int A[110];
int B[110];
int diff[110];
bool isAns = true;
int cnt = 0;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N >> P >> Q;
    int D = P-Q;
    for (int i =0; i<N; ++i) {
        cin >> A[i];
    }
    for (int i =0; i<N; ++i) {
        cin >> B[i];
        diff[i] = A[i]-B[i];
    }
    for (int i =0; i< N; ++i ) {
        int _D = D; 
        if(diff[i]*D > 0) {
            isAns = false;
            break;
        }
        diff[i] = abs(diff[i]);
        _D = abs(_D);
        if (diff[i] == 0){
            diff[i] = 0; continue;
        } else if (D == 0 ){
            isAns =false;
            break;
        }
        int namu = diff[i]%_D;
        if (namu == 0) {
            diff[i] = abs(diff[i]/_D);
            cnt += diff[i];
        } else {
            isAns = false;
            break;
        }
        if (cnt > MAX) {
            isAns = false;
            break;
        }
    }
    if (isAns == false) {
        cout<<"NO"; return 0;
    }
    cout << "YES" << '\n';
    for (int i=0; i< N; ++i) {
        cout << diff[i] << ' ';
    }

    return 0;

}