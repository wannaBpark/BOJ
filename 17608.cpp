#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,input;
	cin >> N;
	while (N--) {
		cin >> input; st.push(input);
	}
	int pivot = 0;
	while (!st.empty()) {
		if (pivot < st.top()) {
			++ans;
			pivot = st.top();
		}
		st.pop();		
	}
	cout << ans << endl;
	return 0;
}