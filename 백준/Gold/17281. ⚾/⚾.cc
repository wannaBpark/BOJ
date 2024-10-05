#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,last;
int ans =0;
vector<int> v[10];
vector<int> order={0,1,2,3,4,5,6,7,8};
int InningResult(int inning) {
    // printf("%dinning %d first\n", inning, last);
    int score = 0, out = 0, hitter, i;
    int base[4] = {0,};
    for(i = last; out != 3; i++) {
        hitter = order[i%9];
        int res = v[hitter][inning];
        // printf("i:%dcur hitter : %d result: %d\n", i%9, hitter,res);
        if (!res) { ++out; continue; }

        score += (res==4) ? 1 : 0; // 타자주자
        for (int j=3; j >=1; --j) {
            int& cur = base[j];
            int nxt = j + res;
            if (!cur) continue;

            if (nxt >= 4) ++score;
            else base[nxt] = cur;
            cur = 0;
        }
        if (res<4) base[res] = true;        
    }
    last = (i%9);
    return score;
}
void solve()
{
    int cnt = 0;
    do {
        if(order[3] != 0) continue;
        int sum = 0;
        last = 0;
        for (int i=0; i <N; ++i) {
            sum += InningResult(i);
            // printf("%d innning %d score\n", i+1, sum);
        }
        
        ans = max(ans, sum);
        // for (int i = 0; i<order.size(); ++i) {
        //     printf("%d ",order[i]);
        // }
        // printf("sum : %d\n", sum);
        // puts("");
        // if (cnt == 0) break;
    } while(next_permutation(order.begin(), order.end()));
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N;
    // v[타자][이닝]
    for (int i =0; i<N; ++i) {
        for (int j =0; j < 9; ++j) {
            int a; cin >> a;
            v[j].push_back(a);
        }
    }
    solve();
    printf("%d", ans);
    return 0;
}