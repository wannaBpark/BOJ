#include <iostream>
const int MAX = 1e6 + 1;
using namespace std;

int Answer;
int dp[MAX] = { 0, };
int f(int a)
{
	if (a == 1 || dp[a]) return dp[a];
	else if (a % 2 == 1) {
		return dp[a] = f(a + 1)+1;
	}
	else {
		return dp[a] = f(a / 2) + 1;
	}
}

int main(int argc, char**argv)
{
	dp[2] = 1;
	int T, test_case,N1,N2;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		cin >> N1 >> N2;
		Answer = 0;
		for (int i = N1; i <= N2; i++) {
			if (dp[i]) Answer += dp[i];
			else Answer += f(i);
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	return 0;
}