#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	//freopen("input.txt", "r", stdin);
	int N, M,T,tmp,index,cnt=0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &N, &M);
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp); 
			q.push({j,tmp}); 
			pq.push(tmp);
		}
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				++cnt;
				pq.pop();
				if (index == M) {
					break;
				}
			}
			else q.push({index,value});
			
		}
		printf("%d\n", cnt);
		cnt = 0;
		
		/*
		while (!pq.empty()) {
			int res = q.front();
			if (res == pq.top()) {
				if (index == 0) {
					break;
				}
				else {
					++cnt;
					q.pop(); pq.pop(); q.push(res); pq.push(res); --index;
				}
			}
			else if (res != pq.top()) {
				++cnt;
				if (index == 0) {
					q.pop(); pq.pop(); q.push(res); pq.push(res); index = pq.size();
				}
				else {
					q.pop(); pq.pop(); q.push(res); pq.push(res); --index;
				}
			}
		}
		while (!pq.empty()) {
			pq.pop();
		}
		while (q.empty()) {
			q.pop();
		}*/
		//printf("%d\n", cnt); cnt = 1;
	}
	
	return 0;
}