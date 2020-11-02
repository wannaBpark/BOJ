#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
double d(double a, double b) {
	return sqrt(a*a + b*b);
}
using namespace std;
vector<pair<int, int> > v;
int r, c;
double ans = 30000;
int main()
{
	scanf("%d%d", &r, &c);
	int a, b;
	for (int i = 0; i < 3; i++) scanf("%d%d", &a, &b), v.push_back({ a,b });
	int A[3] = { 0,1,2 };
	do {
		double cnt = 0;
		cnt += d(v[A[0]].first - r,v[A[0]].second - c);
		for (int i = 1; i < 3; i++) {
			cnt += d(v[A[i]].first - v[A[i - 1]].first, 
				v[A[i]].second - v[A[i - 1]].second);
		}
		ans = min(cnt, ans);
	} while (next_permutation(A, A + 3));
	printf("%d\n",(int)ans);
	return 0;
}