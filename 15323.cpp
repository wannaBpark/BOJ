#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int K,N,index,len;
char c;
vector<string> str[100100];
int cnt[28];
char s[100100];
int main()
{
	freopen("input.txt", "r", stdin);
	//cin >> K >> N;
	scanf("%d%d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%s", &s) , str[s[0] - 'a'].push_back(s);
		//cout << str[s[0] - 'a'];
	}
	for (int i = 0; i < 26; i++)
		if (!str[i].empty()) sort(str[i].begin(), str[i].end());
	for (int i = 0; i < N; i++) {
		//cin >> c;
		scanf("%s", s); 
		index = s[0] - 'a', len = str[index].size();
		/*if (cnt[index] == NULL) {
			printf("%s\n", str[index][cnt[index]++].data());
		}
		else */printf("%s\n", str[index][cnt[index]++%len].data());
		//cout<<str[index][cnt[index]++%size]<<endl;
	}
	return 0;
}