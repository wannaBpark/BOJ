#include <cstdio>
#define min(a,b) {a>b ? b:a}
//#define ll long long
unsigned long long mid,start,N,ans,end;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%llu", &N);
	start = 0; end = 0x100000000; //16ÀÇ 8½Â * 1-> 2ÀÇ 32½Â
	//printf("%llu\n", N);
	//if (N == 0) { puts("0"); return 0; }
	ans = (start + end) / 2;
	while (start <= end) {
		mid = (start + end) / 2;
		printf("%llu\n", ans);
		//ans = mid;
		if (mid*mid > N) {
			end = mid-1; ans = mid;
		}
		else if(mid*mid<N) start = mid+1;
		else {
			ans = mid; break;
		}
		//printf("%llu\n", mid);
	}
	printf("%llu\n", ans);
	return 0;
}
