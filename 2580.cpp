#include <cstdio>
#include<vector>
#include <stdlib.h>
int A[10][10];
using namespace std;
int chkGaro[10][10], chkSero[10][10], chkSquare[10][10];
// chkGaro[i][k] i번째행에 k값이 있는지 체크
// chkSero[j][k] j번째열에 k값이 있는지 체크
// chkSquare[q][k] 제q사분면에 k값이 있는지 체크
vector<pair<int, int> > v;
int getQRow(int row) {
	if (row > 5 && row < 9) return 6;
	else if (row > 2 && row < 6) return 3;
	else return 0;
}
int getQCol(int col) {
	if (col > 5 && col< 9) return 6;
	else if (col > 2 && col < 6) return 3;
	else return 0;
}
int getQuadurant(int row, int col) {
	if (row > 5 && row < 9) { //셋째줄
		if (col > 5 && col< 9) return 9;
		else if (col > 2 && col < 6) return 8;
		else return 7;
	}
	else if (row > 2 && row < 6) { //둘째줄
		if (col > 5 && col< 9) return 6;
		else if (col > 2 && col < 6) return 5;
		else return 4;
	}
	else { //첫째줄
		if (col > 5 && col< 9) return 3;
		else if (col > 2 && col < 6) return 2;
		else return 1;
	}
}
/*
bool chkGaro(int row)
{
	int chk[10] = { 0, };
	for (int i = 0; i < 9; i++) {
		if (chk[A[row][i]] && A[row][i]) return false;
		else chk[A[row][i]]++;
	}
	return true;
}
bool chkSero(int col)
{
	int chk[10] = { 0, };
	for (int i = 0; i < 9; i++) {
		if (chk[A[i][col]] && A[i][col] != 0) return false;
		else chk[A[i][col]]++;
	}
	return true;	
}
bool chkSquare(int row, int col)
{
	int chk[10] = { 0, };
	for (int i = row; i < row+3; i++) {
		for (int j = col; j < col + 3; j++) {
			if (chk[A[i][j]] && A[i][j]!=0) return false;
			else chk[A[i][j]]++;
		}
	}
	return true;
}*/
void backtracking(int index)
{
	//printf("%d\n", index);
	
	if (index >= v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", A[i][j]);
			puts("");
		}
		/*for (int i = 0; i < 9; i++) {
			for (int j = 1; j <= 9; j++) {
				printf("%d ", chkGaro[i][j]);
			}
			puts("");
		}
		puts("");
		for (int i = 0; i < 9; i++) {
			for (int j = 1; j <= 9; j++) {
				printf("%d ", chkSero[i][j]);
			}
			puts("");
		}
		puts("");
		for (int i = 1; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", chkSquare[i][j]);
			}
			puts("");
		}*/
		exit(0);
	}
	int y = v[index].first, x = v[index].second;
	int q = getQuadurant(y, x);;
	//printf("(%d,%d) q: %d\n",y+1,x+1, q);
	for (int i = 1; i <= 9; i++) {
		A[y][x] = i;
		if (!chkGaro[y][i] && !chkSero[x][i] && !chkSquare[q][i]) {
			chkGaro[y][i] = chkSero[x][i] = chkSquare[q][i] = true;
			backtracking(index+1);
			chkGaro[y][i] = chkSero[x][i] = chkSquare[q][i] = false;
		}
	}

	return;
}
int main()
{
	freopen("input.txt", "r", stdin);

	int index = 0;
	for (int i = 0; i < 9; i++) 
		for (int j = 0; j < 9; j++) {
			scanf("%d", &A[i][j]);
			int q = getQuadurant(i,j),tmp = A[i][j];
			if (!A[i][j]) v.push_back({ i,j });
			else if(A[i][j])
				chkGaro[i][tmp] = chkSero[j][tmp] = chkSquare[q][tmp] = true;
		}
	backtracking(0);
	return 0;
}