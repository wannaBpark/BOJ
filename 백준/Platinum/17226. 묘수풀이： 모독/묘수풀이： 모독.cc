#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int N, M, L;
int foundAns = false;
vector<int> v;
vector<bool> v_print;

vector<pii> myCard;
vector<pii> enemy;
vector<int> permutation;
void useModokNow(vector<pii>& myCopy, vector<pii>& enemyCopy)
{
	vector<int> allHealth;
	for (int i = 0; i < N; ++i) {
		if(myCopy[i].second > 0) allHealth.push_back(myCopy[i].second);
	}
	for (int i = 0; i < M; ++i) {
		if (enemyCopy[i].second > 0) allHealth.push_back(enemyCopy[i].second);
	}

	
	sort(allHealth.begin(), allHealth.end());
	/*printf("sorted all Health\n");
	for (auto& i : allHealth) {
		printf("%d ", i);
	}
	puts("");*/
	int ret = 1; 
	for (int i = 0; i < allHealth.size(); ++i) {
		if (allHealth[i] - ret > 1) {
			break;
		} else if (allHealth[i] - ret == 1) {
			++ret;
		}
	}
	if (allHealth[0] != 1) ret = 1;

	for (int i = 0; i < N; ++i) {
		myCopy[i].second -= ret;
	}
	for (int i = 0; i < M; ++i) {
		enemyCopy[i].second -= ret;
	}
	/*printf("myHealth\n");
	for (auto& i : myCopy) {
		printf("%d ", i.second);
	}
	puts("");
	printf("EnemyHealth\n");
	for (auto& i : enemyCopy) {
		printf("%d ", i.second);
	}
	puts("");
	printf("ret : %d\n", ret);*/
}
bool isAllDead(vector<pii>& enemyCopy)
{
	int ret = true;
	for (int i = 0; i < enemyCopy.size(); ++i) {
		//cout << i+1 << "번째 " << enemyCopy[i].second << endl;
		if (enemyCopy[i].second > 0) ret = false;
	}
	//cout << "asdfasdf" << endl;
	return ret;
}
void f(vector<int>& permutation, vector<int>& order, vector<pii> myCopy, vector<pii> enemyCopy, int UsedModok, int useNow, int idx)
{
	/*printf("cur : %d  UsedModok? : %d\n", idx, UsedModok);
	
	printf("cur permutation\n");
	for (int i = 0; i < permutation.size(); ++i) {
		printf("%d ", permutation[i]);
	}
	puts("");*/

	if (foundAns == true) return;

	if (useNow == true) {
		//printf("------------------\n");
		//puts("USE MODOK!!");
		useModokNow(myCopy, enemyCopy);
		//printf("------------------\n");
	}	
	if (order.size() > 0) {
		/*printf("------------------\n");
		printf("cur order\n");
		for (int i = 0; i < order.size(); ++i) {
			printf("%d ", order[i]);
		}
		puts("");*/

		/*printf("myHealth\n");

		for (auto& i : myCopy) {
			printf("%d ", i.second);
		}
		puts("");
		printf("EnemyHealth\n");
		for (auto& i : enemyCopy) {
			printf("%d ", i.second);
		}
		puts("");
		printf("------------------\n");*/
	}


	if (isAllDead(enemyCopy) == true) {
		foundAns = true;
		//cout << "asdf" << endl;
		cout << order.size() << endl;
		int pIdx = 0;
		for (int i = 0; i < order.size(); ++i) {
			//printf("WTf : %d\n", order[i]);
			if (order[i] == -1) puts("use modok");
			else {
				printf("attack %d %d\n", permutation[pIdx++] + 1, order[i] + 1);
			}
		}
		//printf("FOUNDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n");
		return;
	}
	
	if (idx >= N) {
		return;
	}
	int cur = permutation[idx];
	
	if (myCopy[cur].second <= 0) {
		f(permutation, order, myCopy, enemyCopy, UsedModok, 0, idx + 1);

		if (UsedModok == false) { // 아직 안 썼으면
			order.push_back(-1);
			f(permutation, order, myCopy, enemyCopy, 1, 1, idx + 1);
			order.pop_back();
		}
		return;
	}
	for (int j = 0; j < M; ++j) {
		if (enemyCopy[j].second > 0) {
			int myAttack = myCopy[cur].first; int enemyAttack = enemyCopy[j].first;
			/*printf("--------------------Before Attack--------------------\n");
			printf("myHealth\n");

			for (auto& i : myCopy) {
				printf("%d ", i.second);
			}
			puts("");
			printf("EnemyHealth\n");
			for (auto& i : enemyCopy) {
				printf("%d ", i.second);
			}
			puts("");
			printf("Attack %d <-> %d!!\n", cur + 1, j + 1);
			printf("myHealth\n");
			for (auto& i : myCopy) {
				printf("%d ", i.second);
			}
			puts(""); printf("EnemyHealth\n"); for (auto& i : enemyCopy) {printf("%d ", i.second);} puts("");
			printf("--------------------AAAAAAAAAAAAAAAAAAAAAfter Attack--------------------\n");*/


			myCopy[cur].second -= enemyAttack;
			enemyCopy[j].second -= myAttack;
			order.push_back(j);
			f(permutation, order, myCopy, enemyCopy, UsedModok, 0, idx + 1);
			order.pop_back();
			myCopy[cur].second += enemyAttack;
			enemyCopy[j].second += myAttack;
			
			
			if (UsedModok == false) { // 아직 안 썼으면
				order.push_back(j);
				order.push_back(-1);
				myCopy[cur].second -= enemyAttack;
				enemyCopy[j].second -= myAttack;
				f(permutation, order, myCopy, enemyCopy, 1, 1, idx + 1);
				myCopy[cur].second += enemyAttack;
				enemyCopy[j].second += myAttack;
				order.pop_back();
				order.pop_back();
			}
		}
	}
}
int main()
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	int attack, health;
	for (int i = 0; i < N; ++i) {
		cin >> attack >> health; myCard.push_back({ attack, health });
	}
	for (int i = 0; i < M; ++i) {
		cin >> attack >> health; enemy.push_back({ attack, health });
	}

	for (int i = 0; i < N; ++i) permutation.push_back(i);

	vector<int> order;

	if (M == 0 || isAllDead(enemy) == true) {
		puts("0");
		return 0;
	}

	do {
		vector<pii> myCopy = myCard;
		vector<pii> enemyCopy = enemy;

		f(permutation, order, myCopy, enemyCopy, 0, 0, 0);

		myCopy.clear(); myCopy = myCard;
		enemyCopy.clear(); enemyCopy = enemy;
		
		order.push_back(-1);
		f(permutation, order, myCopy, enemyCopy, 1, 1, 0);
		order.pop_back();
		if (foundAns == true) break;
	} while (next_permutation(permutation.begin(), permutation.end()));

	if (foundAns == false) {
		cout << "-1" << endl;

	}
	return 0;
}