#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int N, S, A[40];
ll ans = 0;
vector<int> v2;
vector<int> v1;
//meet in middle
// 분할
void back(int index, int cnt, int start, int end, int dir)
{
	if (index >= start) {
		if(cnt == S) ans++;
		if (!dir) v1.emplace_back(cnt);
		else if (dir) v2.emplace_back(cnt);
	}
	for (int i = index + 1; i < end; i++) {
		if(!dir) back(i, cnt + A[i],start,end,dir);
		else if (dir) back(i, cnt + A[i], start, end, dir);
	}
}
int main()
{
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	int mid = N / 2;
	printf("mid : %d\n", mid);
	back(-1,    0,  0,  mid, 0);
	back(mid-1, 0,  mid, N,  1);
	int arr[3] = { 1,2,3 };
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) {
		int x = v1[i];
		//vector<int>::iterator upper
		//배열로 했을떄에는
		//int *upper= upper_bound(arr,arr+n, 찾고자하는 값);
		auto upper = upper_bound(v2.begin(), v2.end(), S - x);
		auto lower= lower_bound(v2.begin(), v2.end(), S - x);
		//int up = upper - v2.begin(), low = lower - v2.begin();
		ans += upper - lower;
	}


	//for (auto i : v1) printf("%d ", i);
	//puts("");
	//for (auto i : v2) printf("%d ", i);
	//puts("");
	//int left = 0, right = v2.size()-1;
	//
	//while (right >=0 && left!=v1.size()) {
	//	//printf("%d %d\n", left, right);
	//	if (v1[left] + v2[right] > S) right--;
	//	else if (v1[left] + v2[right] == S) { ++ans; right--; }
	//	else left++;
	//}
	//if (right < 0) {
	//	for (; left < v1.size(); left++) {
	//		if (v1[left] + v2[0] > S) break;
	//		else if (v1[left] + v2[0] == S) ++ans;
	//	}
	//}
	//else if (left >=v1.size()) {
	//	int sz = v1.size() - 1;
	//	for (;  right >= 0; right--) {
	//		if (v1[sz] + v2[right] < S) break;
	//		else if (v1[sz] + v2[right] == S) ++ans;
	//	}
	//}
	/*while (left != v1.size() - 1) {
		if(v1[left]+v2[right]>S)
	}*/
	printf("%lld\n", ans);
	return 0;
}