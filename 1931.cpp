#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,ans=1,nxt=0;
vector<pair<int, int> > v;
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++)
		cin >> a >> b, v.emplace_back(make_pair(b, a));
	sort(v.begin(), v.end());
	for (int i = 1; i < N; i++) {
		//(���� ȸ�� ����ð��� ���纸�� ũ�ų� ����,) ���� ���۽ð��� ���� ����ð����� ũ�ų� ������.
		if (/*v[nxt].first <= v[i].first &&*/ v[i].second >= v[nxt].first) ++ans,nxt=i; //�̹� �����س������Ƿ� �翬�ϴ�
		cout << v[i].first << " " << v[i].second << endl;
	}
	cout << ans;
	return 0;
}