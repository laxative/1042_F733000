#include<iostream>
#include<cstring>
#include<new>
using namespace std;
int Sudoku[9][9];
int square;
bool usedInRow(int row, int num) {
	for(int i=0;i<square*square;i++) {
		if(num==Sudoku[row][i]) return true;
	}
	return false;
}
bool usedInCol(int col, int num) {
	for(int i=0;i<square*square;i++) {
		if(num==Sudoku[i][col]) return true;
	}
	return false;
}
bool usedInBox(int row, int col, int num) {
	for(int i=row/square*square;i<row/square*square+square;i++) {
		for(int j=col/square*square;j<col/square*square+square;j++) {
			if(num==Sudoku[i][j]) return true;
		}
	}
	return false;
}
bool isSafe(int row, int col, int num) {
	if((!usedInRow(row,num) && !usedInCol(col,num)) && !usedInBox(row,col,num)) return true;
	return false;
}
int *findblank() {
	int *blank = new int[2];
	for(int i=0;i<square*square;i++) {
		for(int j=0;j<square*square;j++) {
			if(Sudoku[i][j]==0) {
				blank[0] = i;
				blank[1] = j;
				return blank;
			}
		}
	}
	blank[0]=-1;
	blank[1]=-1;
	return blank;
}
bool backtracking() {
	int *Blank = findblank();
	int row,col;
	row = Blank[0];
	col = Blank[1];
	if(row<0) return 1;
	for(int i=1;i<=square*square;i++) {
		if(isSafe(row,col,i)) {
			Sudoku[row][col] = i;
			if(backtracking()) return 1;
			Sudoku[row][col] = 0;
		}
	}
	return 0;
}
void solve() {
	if(backtracking()) {
		for(int i=0;i<square*square;i++) {
			for(int j=0;j<square*square;j++) {
				if(j) cout << " ";
				cout << Sudoku[i][j];
			}
			cout << endl;
		}
		return;
	}
	cout << "NO SOLUTION" << endl;
	return;
}
int count=0;
int main() {
	while(cin >> square) {
		if(count) cout << endl;
		memset(Sudoku[0],0,81*sizeof(int));
		for(int i=0;i<square*square;i++) {
			for(int j=0;j<square*square;j++)  cin >> Sudoku[i][j];
		}
		solve();
		count++;
	}
	return 0;
}
