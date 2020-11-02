#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<int> s;
int N;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		string c; int a;
		cin >> c;
		if (c == "push") {
			cin>>a; s.push(a);
		}
		else if (c == "pop") {
			if (!s.empty()) {
				int x = s.top(); cout << x << endl;
				s.pop();
			}
			else cout << "-1" << endl;
		}
		else if (c == "size") {
			cout << s.size() << endl;
		}
		else if (c == "empty") {
			if (s.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (c == "top") {
			if (s.empty()) cout << "-1" << endl;
			else cout << s.top() << endl;
		}
	}
	return 0;
}