#include <queue>
#include <cstdio>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> > min_heap;
priority_queue<int> max_heap;
int N,a;
int ans = 0;
int main()
{
	scanf("%d", &N);
	int top, sec;
	while (N--) {
		scanf("%d", &a);
		if (a > 0) max_heap.push(a);
		else min_heap.push(a);
	}
	while (!min_heap.empty()) {
		if (min_heap.size() == 1) {
			top = min_heap.top(); min_heap.pop();
			ans += top; 
		}
		else {
			top = min_heap.top(); min_heap.pop();
			sec = min_heap.top(); min_heap.pop();
			ans += top*sec;
		}
	}
	while (!max_heap.empty()) {
		if (max_heap.size() == 1) {
			top = max_heap.top(); max_heap.pop();
			ans += top; 
		}
		else {
			top = max_heap.top(); max_heap.pop();
			sec = max_heap.top(); max_heap.pop();
			if (sec == 1) {
				ans += top + sec;
				continue;
			}
			ans += top*sec;
		}
	}
	printf("%d\n", ans);
	return 0;
}