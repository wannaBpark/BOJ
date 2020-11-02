#include<iostream>
#include <algorithm>
using namespace std;
int N;
struct O {
	int g;
	int s;
	int b;
};
bool cmp(const O &i, const O &j) {
	if (i.g == j.g) {
		if (i.s == j.s) {
			return i.b > j.b;
		}
		else return i.s > j.s;
	}
	return i.g > j.g;
}
int main()
{
	O Olym[1001];
	int tmp,K;
	cin >> N>>K;
	for (int i = 0; i < N; i++) cin >> tmp>>Olym[i].g >> Olym[i].s >> Olym[i].b;
	sort(Olym, Olym + N,cmp);
	int nxt = 0, rank = 1;
	O Ok = Olym[K - 1];
	for (int i = 0; i < N; i++) {
		//cout <<Olym[i].g << Olym[i].s << Olym[i].b << endl;
	}
	return 0;
}