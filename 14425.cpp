#include<iostream>
#include<string>
#include<stack>
#include<math.h>
#include<memory.h>
#include<utility>
#include<algorithm>
#include<vector>
#include<map>
#include<stdlib.h>
#include<queue>
#include<stdio.h>
using namespace std;
typedef long long  ll;
typedef pair<int, int> P;
map<int, int> trie[5001000];
int root = 1;
int cur;
string s;
int n, m;
int cnt = 1;
bool marking[5001000];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int size = s.size();
		cur = root;
		for (int j = 0; j < size; j++)
		{
			if (trie[cur][s[j]] == 0)
			{
				trie[cur][s[j]] = ++cnt;
				cur = trie[cur][s[j]];
			}
			else
				cur = trie[cur][s[j]];
		}
		//cout << cur << '\n';
		marking[cur] = true;
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		int size = s.size();
		cur = root;
		for (int j = 0; j < size; j++)
		{
			if (trie[cur].count(s[j]))
				cur = trie[cur][s[j]];
			else
				break;
		}
		//cout << cur << '\n';
		if (marking[cur])
			ans++;

	}

	cout << ans << '\n';
	return 0;
}