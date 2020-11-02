#include <cstdio>
#include <vector>
//�������� �������ִ� �ִ� ��󰳼� + �Ͼ翡�� �������ִ� �ִ� ��󰳼�
//2�� N*N��(����) -> 2�� (N/2)*(N/2)������ ����.
// �ؿ� 2 �ٴ�����(�����ϵ� �������ϵ� ����� ���������ְ� ���������ֱ� ����)
using namespace std;
struct Edge {
	int left, right;
};
int max(int a, int b) { return a > b ? a : b; }
int left[21], right[21];
int N, ans[2], color;
int A[12][12];
vector<pair<int, int> > p[2];
//bool isPossible(int )
//{
//	// abs() ()�� ���ƾ��Ѵ�.
//}
void backtracking(int index, int cnt, int color)
{
	//printf("%d %d\n", index,cnt);
	ans[color] = max(cnt, ans[color]);
	if (cnt + (p[color].size() - 1 - index) <= ans[color]) { //�� Ž���غ��� ���� ans���� ������
		return;
	}
	//printf("y: %d x: %d\n", y, x);
	for (int i = index + 1; i < p[color].size(); i++) {
		int y = p[color][i].first, x = p[color][i].second;
		if (!left[y + x - 1] && !right[y - x + N]) {
			//printf("asdfa\n");
			left[y + x - 1] = right[y - x + N] = true;
			backtracking(i, cnt + 1, color);
			left[y + x - 1] = right[y - x + N] = false;
		}
	}

	return;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			//printf("%d ", A[i][j]);
			if (i + j & 1 && A[i][j]) p[0].push_back({ i,j });
			else if (!(i + j & 1) && A[i][j]) p[1].push_back({ i,j });
		}
	}
	backtracking(-1, 0, 0);
	backtracking(-1, 0, 1);

	printf("%d\n", ans[0]+ans[1]);
	return 0;
}