#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

//
//int min[9999];
//int max[9999];
int T, M,num,tmp;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &M);
		printf("%d\n", (M + 1) / 2);

		priority_queue<int,vector<int>, greater<int>> min_h;
		priority_queue<int> max_h;
		for (int i = 1; i <= M; i++) {
			scanf("%d", &num);

			if (min_h.size() == max_h.size()) {
				if (min_h.empty()) {
					max_h.push(num);
				}
				else {
					if (min_h.top() <= num) {
						tmp = min_h.top();
						min_h.pop();
						min_h.push(num);
						num = tmp;
					}
					max_h.push(num);
				}
			}
			else {
				if (max_h.top() > num) {
					tmp = max_h.top();
					max_h.pop();
					max_h.push(num);
					num = tmp;
				}
				min_h.push(num);
			}
			if (i % 2==1) printf("%d ", max_h.top());
			

		}	
		printf("\n");
	}
	return 0;
}