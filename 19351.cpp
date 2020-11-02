#include <iostream>
#include <string>
using namespace std;
int N;
string s;
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	cin.ignore(256, '\n');
	while (N--) {
		getline(cin, s);
		int sum = 0;
		for (int i = 0; i < size(s); i++) {
			printf("%c ", s[i]);
			if(s[i] != ' ') sum += (s[i]-'A'+1);
		}
		puts("");
		if (sum == 100) printf("PERFECT LIFE\n");
		else printf("%d\n", sum);
	}
	return 0;
}