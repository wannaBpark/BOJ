/*
�ٽ� �� �ʿ� �ִ� ����.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int> > v;
int d(vector<pair<int, int> >& v, int l, int r) //�Ź� ���� ���� ������
{
	int dx = v[l].first - v[r].first;
	int dy = v[l].second - v[r].second;
	return dx*dx + dy*dy;
}
int dc(int l, int r)
{
	int minD = 0x100000000 *2;
	int mid = (l + r) / 2;
	int length = r-l + 1;
	if (length <= 3) { //3�� ���ϸ� ���̻� ���� x, ��� ��
		for (int i = l; i < r; i++)
			for (int j = i + 1; j <= r; j++) 
				minD = min(minD,d(v, i, j));
	}
	//printf("%d %d %d\n", l, r, length);
	vector<pair<int, int> > temp;
	for (int i = l; i <= r; i++) {
		int dy = v[i].second - v[mid].second;
		if (dy*dy < minD) temp.push_back(v[i]); //y��ǥ ���̰� minD���� ũ�ٸ� ���ʿ� x
	}
	sort(temp.begin(), temp.end()); //x��ǥ ����
	for (int i = 0; i < temp.size() - 1; i++) {
		for (int j = i + 1; j < temp.size(); j++) {
			int dx = temp[i].first- temp[j].first;
			if (minD > dx*dx) minD = min(minD, d(temp, i, j));
			else break;
		}
	}
	return minD;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	int x, y;
	for (int i = 0; i < N; i++) scanf("%d%d", &x, &y), v.push_back({ x,y });
	sort(v.begin(), v.end()); //x��ǥ ���� -> y�࿡ ������ �������� ��������
	printf("%d\n", dc(0, N - 1));
	return 0;
}