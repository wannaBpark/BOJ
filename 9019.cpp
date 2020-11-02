#include <cstdio>
#include <queue>
using namespace std;
int T,index= 1;
struct jari {
	int d1, d2, d3, d4;
};
queue<jari> q;
jari J(int tmp)
{
	int d[5], index = 1;
	while (tmp != 0) {
		d[index++] = tmp % 10;
		tmp /= 10;
	}
	return{d[1],d[2],d[3],d[4]};
}
int main()
{
	int a, b,n,tmp;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b); tmp = a;
		int d[7] = { 0, };
		int visited[1010] = { 0, };
		while (tmp != 0) {
			d[index++] = tmp % 10;
			tmp /= 10;
		}
		int d1 = d[1], d2 = d[2], d3 = d[3], d4 = d[4];
		q.push({d1,d2,d3,d4});
		n = 1000 * d4 + 100 * d3 + 10 * d2 + d1;
		visited[n] = true;
		while (!q.empty()) {
			int d1 = q.front().d1, d2 = q.front().d2,
				d3 = q.front().d3, d4 = q.front().d4;
			n = 1000 * d4 + 100 * d3 + 10 * d2 + d1;
			
			q.pop();
			
			tmp = 2 * n % 10000;
			if (!visited[tmp]) q.push(J(tmp));

		}
	}
	return 0;
}