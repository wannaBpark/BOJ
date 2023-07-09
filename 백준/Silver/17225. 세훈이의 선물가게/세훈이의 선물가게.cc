#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

priority_queue< pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>> > pq;
vector<int> v1;
vector<int> v2;

int A,B,N;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> A >> B >> N;
	
	int cnt1 =0, cnt2 =0;
	for(int i=0; i<N; i++){
		int t, m, time; 
		char c;
		
		cin >> t >> c >> m;
		
		if(c == 'B'){
			if(cnt1 > t) t = cnt1;
			
			for(int j=0; j<m; j++)
				pq.push(make_pair(j*A + t, c));
            
			cnt1 = t+A*m;
		}
		else {
			if(cnt2 > t) t = cnt2;
			
			for(int j=0; j<m; j++)
				pq.push(make_pair(j*B + t, c));
			
			cnt2 = t+B*m;
		}
		
	}
	
	int cnt = 1;
	while(!pq.empty()){
		int c = pq.top().second;
		pq.pop();
		
		if(c == 'B') v1.push_back(cnt);
		else v2.push_back(cnt);
		
		++cnt;
	}
	
	cout << v1.size() << endl;
	for(auto it : v1)
		cout << it << " ";
	cout << endl;
	
	cout << v2.size() << endl;
	for(auto it : v2)
		cout << it << " ";
	cout << endl;

	return 0;
}