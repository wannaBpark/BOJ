#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,index= 0;
int A[1001000];
int sosu[1001000];
vector<int> v;
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	A[1] = 1;

	for (int i = 2; i <= 1000000; i++) {
		if (!A[i]) { sosu[index++]=i/*, printf("%d\n", i)*/; }
		else continue;
		for (int j = i*2; j <= 1000000; j += i) {
			A[j] = true;
		}
	}

	//for (int i = 0; i < index; i++) {
	//	printf("%d\n", sosu[i]);
	//}
	int a;

	while (1) {
		scanf("%d", &a);
		if (a == 0) break;
		for (int i = 3; i <= a; i++) {
			if (!A[i] && !A[a - i]) {
				printf("%d = %d + %d\n", a, i, a - i);
				//cout << a << " = " << i << " + " << a - i << endl;
				break;
			}
		}
	}
	//do {
	//	bool isPossible = false;
	//	int *lower = lower_bound(sosu, sosu+index, a);
	//	//int upper = upper_bound(v.begin(), v.end(), a)-v.begin();
	//	int low = lower - sosu;
	//	for (int i = low-1; i > 0;i--) {
	//		int x = sosu[i];
	//		//printf("%d\n", x);
	//		if (A[sosu[i]] == false && A[a - sosu[i]] == false) {
	//			cout << a << " = " << a-sosu[i] << " + " << sosu[i] << endl;
	//			isPossible = true;
	//			break;
	//		}
	//		/*if (!A[x] && x&1) {
	//		cout << a << " = " << x << " + "<< v[i] <<endl;
	//		isPossible = true; break;
	//		}*/
	//	}
	//	if(!isPossible) cout << "Goldbach's conjecture is wrong." << endl;
	//	cin >> a;
	//} while (a != 0);
	return 0;
}