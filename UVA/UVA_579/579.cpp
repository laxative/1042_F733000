#include<iostream>
#include<iomanip>
using namespace std;
void clockhands(double i, double j) {
	if(i==12)	i=0;
	i *= 5;
	i += j/12;
	float answer;
	if(j>i) {
		answer = (j-i) * 6;
	}else{
		answer = (i-j) * 6;
	}
	if(answer>180) answer = 360 - answer;
	cout << fixed << setprecision(3);
	cout << answer << endl;
}
int main() {
	float i,j;
	char c;
	while(cin >> i >> c >> j) {
		if(i==0 && j==0) break;
		clockhands(i,j);
	}
	return 0;
}
