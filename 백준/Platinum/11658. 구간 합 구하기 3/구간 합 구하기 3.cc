#include <cstdio>
#define MX_N 1050
#define MX_K 1e5
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

int Fenwick_Tree[MX_N][MX_N];

int MX_INPUT = -1;
int M, N, K, W;
int arr[MX_N][MX_N];

int Sum(int row ,int col)
{
    ll res = 0;
    for (int i = row; i > 0; i -= (i & -i)) {
        for (int j = col; j > 0; j -= (j & -j)) {
            res += Fenwick_Tree[i][j];
        }
    }
    return res;
}

void Update(int row, int col, int val)
{
    for (int i = row; i <= N; i += (i & -i)) {
        for (int j = col; j <= N; j += (j & -j)) {
            Fenwick_Tree[i][j] += val;
        }
    }
}

// 0 ~ K 까지 범위 유의
int main()
{
    scanf("%d %d", &N, &M); 
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &arr[i][j]);
            Update(i, j, arr[i][j]);
        }
    }

    int w, x, y, c;
    int x1, x2, y1, y2;
    while (M--) {
        scanf("%d", &w);
        if (w == 0) {
            scanf("%d %d %d", &x, &y,&c);
            Update(x, y, c - arr[x][y]);
            arr[x][y] = c;
        } else if (w == 1) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            int ret = Sum(x2, y2) - Sum(x1 - 1, y2) - Sum(x2, y1 - 1) + Sum(x1 - 1, y1 - 1);
            printf("%d\n", ret);
        }
    }

    return 0;
}