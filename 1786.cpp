#include <iostream>
#include <string>
#include <vector>
using namespace std;
int fail[1 << 20];
int ans[1 << 20];
string s, p;
int sz = 0;
void make_fail()
{
	int i = -1, j = 0;
	fail[0] = -1;
	while (j< p.size()) {
		if (i < 0 || p[i] == p[j]) {
			i++, j++;
			fail[j] = i;
		}
		else
			i = fail[i];
	}
}
void matching() {
	int i = 0, j = 0;
	while (j < s.size()) {
		if (i < 0 || p[i] == s[j]) {
			i++, j++;
		}
		else i = fail[i];
		if (i == p.size()) {
			ans[sz++] = j;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	getline(cin, p);
	make_fail();
	matching();
	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << ans[i]-p.size()+1 << " ";
	return 0;
}