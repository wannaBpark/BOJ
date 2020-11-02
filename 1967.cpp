#include <iostream>
#include <vector>
#include<utility>
#include <algorithm>
using namespace std;
int N,ans;
vector<pair<int,int>> v[10001];
vector<int> mCost[10001];

int dc(int par, int cost)
{
	//printf("%d %d\n", par, cost);
	//if (v[par].empty()) { printf("���� �ڽľ��� ������: %d %d\n", par,cost); return cost; }
	//if (v[par].size() == 1 && v[v[par][0].first].empty()) return cost+v[par][0].second;
	for (int i = 0; i < v[par].size(); i++) {
		int child = v[par][i].first, val = v[par][i].second;
		//printf("%d %d\n", child, val);
		int mx = val;
		if (!v[child].empty()) { //�ڽ��� ���� ���� Ž������ ���Ѵ�
			mx += dc(child, cost+val);
		}
		mCost[par].push_back(mx);
	}
	if (mCost[par].size() == 1) {
		ans = max(cost + mCost[par][0], ans);
		//�ڽ��� �ϳ��϶�, ����� �� 2)���� �ش��Ѵ�.
		return mCost[par][0];	//�ڽ��� �ϳ� �����ִ� ���.
		//������ �ڽ��� ���� ���� Ž������ ���Ѵ�.(!v[chlid].empty())
	}
	sort(mCost[par].begin(), mCost[par].end());
	int length = mCost[par].size();
	int tmp = max(mCost[par][length - 1], mCost[par][length - 2]);
	//printf("first %d %d\n", mCost[par][length - 1] + mCost[par][length - 2], ans);
	ans = max(mCost[par][length - 1] + mCost[par][length - 2], ans);
	// ���� ����� �ڽ� �ΰ��� ���ѰͰ� ans�� ��
	// �ڽ� 2
	//printf("second %d %d\n", tmp + cost, ans);
	ans = max(tmp + cost, ans);
	//���� ����� �ڽ� ��� �� �ִ� ��(tmp) + ���� ����� ����(��Ʈ)���� ��(cost)
	// = �ڽ�1+�θ�1
	return max(mCost[par][length - 1],mCost[par][length - 2]);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	int a,b,c;
	for (int i = 0; i < N - 1; i++) cin >> a >> b >> c, v[a].push_back({ b,c });
	//����Ǽ��� ����������� ������ : 1) �ڽ� �ΰ�(�Ʒ���) 2) �ڽ�1, �θ�1 (��1�Ʒ�1)
	/*for (int i = 1; i <= N; i++) {
		if(v[i].size() >1)
	}*/
	dc(1, 0);
	cout<< ans <<endl;
	return 0;
}