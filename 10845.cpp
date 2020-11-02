#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
queue<int> q;
int N, input;
string s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> s;
		if (s=="push") {
			cin>>input;
			q.push(input);
		}
		else if (s=="front") printf("%d\n", (q.empty()) ? -1 : q.front());
		else if (s=="empty") printf("%d\n", q.empty());
		else if (s=="back") printf("%d\n", (q.empty()) ? -1 : q.back());
		else if (s=="size") printf("%d\n", q.size());
		else if (s=="pop") {
			if (q.empty()) puts("-1");
			else {
				printf("%d\n", q.front());
				q.pop();
			}			
		}
	}
	return 0;
}