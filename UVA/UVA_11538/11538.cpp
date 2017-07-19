#include<iostream>
using namespace std;
int main() {
	long long int attack;
	long long int row, column, lg, sht;
	while(cin >> row >> column) {
		attack = 0;
		if(row == 0 && column == 0) break;
		attack += row*column*(row-1);  //row
		attack += column*row*(column-1);  //column
		lg = row>column?row:column;
		sht = row>column?column:row;
		attack += 2*(((lg-sht+1)*sht*(sht-1))+(4*(sht*(sht-1)*(sht-2))/6));
		cout << attack << endl;
	}
}
