#include <iostream>
#define dist(a,b,c,d) (c-a)*(c-a)+(d-b)*(d-b)
using namespace std;
int T,N;
int a,b,c,d, cX, cY, R;

bool checkIn(int x, int y)
{
	if (dist(x, y,cX,cY) < R*R) return true; //행성 안에 있을때
	return false;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d;
		cin >> N;
		int ans = 0;
		for(int i=0; i<N; i++){
			cin >> cX >> cY >> R;
			if (checkIn(a, b) != checkIn(c, d)) ++ans;
		}
		cout << ans << endl;
	}

}