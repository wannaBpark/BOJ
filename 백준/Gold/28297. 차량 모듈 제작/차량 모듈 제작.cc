#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
vector<tuple<int, int, int>> v_input;
vector<tuple<double, int, int>> v_dist;
int visited[1010] = { 0, };
int p[1010] = { 0, };
int N;
const double PI = 3.14159265358979323;
const double EPSILON = 1e-6;
double euclid_dist(int x1, int x2, int y1, int y2)
{
	return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}
int distance(int x1, int x2, int y1, int y2, int r1, int r2)
{
	int dist = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);

	if ( dist  > (r1 + r2) * (r1 + r2)) {
		return dist;
	} else {
		return 0;
	}
}

double calculate(tuple<int, int, int> t1, tuple<int, int, int> t2)
{
	int x1, x2, y1, y2, r1, r2;
	double ret = 0, d;
	if (get<2>(t1) > get<2>(t2)) swap(t1, t2);

	x1 = get<0>(t1); y1 = get<1>(t1); r1 = get<2>(t1);
	x2 = get<0>(t2); y2 = get<1>(t2); r2 = get<2>(t2);
	if (r1 > r2) {
		swap(x2, x2); swap(y1, y2); swap(r1, r2);
	}
	d = euclid_dist(x1, x2, y1, y2);
	double cos = (double)(r2 - r1) / d;
	double theta = acos(cos);
#if DEBUG == true
	printf("theta : %.5lf\n", theta);
#endif
	ret +=  2.f * d * sin(theta); 
	ret += r1 * 2.f * theta;
	ret += 2.f * r2 * (PI - theta);

	return ret;
}
int find(int a)
{
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void merge(int a, int b)
{
	int p1 = find(a); int p2 = find(b);
	if (p1 == p2) return;
	// merge to the Bigger parents
	if (p1 < p2) {
		p[p1] = p2;
	} else {
		p[p2] = p1;
	}
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x, y, radius;
		cin >> x >> y >> radius;
		v_input.push_back(make_tuple(x,y,radius));
		p[i+1] = i+1;
	}

	for (int i = 0; i < N - 1; ++i) {
		auto& ta = v_input[i];
		for (int j = i + 1; j < N; ++j) {
			auto& tb = v_input[j];

			int x1, x2, y1, y2, r1, r2;
			x1 = get<0>(ta); y1 = get<1>(ta); r1 = get<2>(ta);
			x2 = get<0>(tb); y2 = get<1>(tb); r2 = get<2>(tb);

			double dist = distance(x1, x2, y1, y2, r1, r2);
			if (dist != 0) {
				dist = calculate(ta, tb);
			}
			v_dist.push_back(make_tuple(dist, i+1, j+1));
		}
	}
	sort(v_dist.begin(), v_dist.end());
	double ans = 0;
	for (auto& t : v_dist) {
		int a = get<1>(t); int b = get<2>(t);
		int p1 = find(a); int p2 = find(b);
		double len = get<0>(t);
		if (p1 != p2) {
			if (len > EPSILON) {
				ans += len;
			}
			merge(p1, p2);
		}

	}

	printf("%.15lf", ans);
	return 0;
}