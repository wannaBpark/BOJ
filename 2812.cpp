#include <iostream>
#include <queue>
using namespace std;
int N,K,input;
priority_queue<int> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>K>>input;
	while (input) {
		pq.push(input % 10);
		input /= 10;
		cout << input << endl;
	}
	for (int i = 0; i < N - K; i++) {
		cout << pq.top();
		pq.pop();
	}
	return 0;
}