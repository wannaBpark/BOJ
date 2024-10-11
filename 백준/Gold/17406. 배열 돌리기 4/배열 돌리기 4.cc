#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
struct op{
    int r, c ,s;
};

int A[60][60];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M, K;
vector<op> v;
vector<int> order;
int arr[60][60];

static inline int OutOfRange(int sx, int sy, int ex, int ey, int x, int y) {
    return ((x>ex) || (x<sx) || (y>ey) || (y<sy));
}

void rotate(int x1, int y1, int x2, int y2) {
    int& endX = x2; int& startX = x1;
    int& endY = y2; int& startY = y1;
    int dir = 0;
    int tmp = arr[startX][startY];
    int nx = startX; int ny = startY;
    while (true) {
        int& dest = arr[nx][ny];
        int IsOut = OutOfRange(x1,y1,x2,y2, nx + dx[dir], ny + dy[dir]);
        
        dir += (IsOut == true) ? 1 : 0;
        if (dir >= 4) break;
        
        nx = nx + dx[dir]; ny = ny + dy[dir];
        int& from = arr[nx][ny];
        dest = from;
    }
    arr[startX][startY+1] = tmp;
}

void operation(int r, int c, int s) {
    for (int i = 1; i <= s; ++i) {
        rotate(r-i, c-i, r+i, c+i);
    }
}

int calculate() {
    int ans = 1e10;
    for (int i = 1; i <= N; ++i) {
        int sum = 0; 
        for (int j = 1; j <= M; ++j) {
            sum += arr[i][j]; 
        }
        ans = min(ans, sum);
    }
    return ans;
}
void copyValue() {
    for (int i = 1; i<=N; ++i) for(int j =1; j<=M; ++j) arr[i][j] = A[i][j];
}
void solve() {
    int ans = 1e10;
    do {
        copyValue();
        for (int i = 0; i < order.size(); ++i) {
            auto& cur = v[order[i]];
            operation(cur.r, cur.c, cur.s);
        }
        
        ans = min(ans, calculate());
    } while( next_permutation(order.begin(), order.end()) );
    cout << ans;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i<= N; ++i) {
        for (int j = 1; j <=M; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < K; ++i) {
        order.push_back(i);
        int r,c,s;
        cin >> r >> c >> s;
        v.push_back({r,c,s});
    }
    solve();
    return 0;
}