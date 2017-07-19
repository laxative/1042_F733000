#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int lines;
	cin >> lines;
	float numbers[lines][2];
	for(int i=0;i<lines;i++) {
		cin >> numbers[i][0] >> numbers[i][1];
	}
	cout << fixed << setprecision(2);
	float answer;
	for(int i=0;i<lines;i++) {
		answer = numbers[i][0] *(9.0/5.0) + 32 + numbers[i][1];
		answer = (answer-32)*(5.0/9.0);
		cout << "Case " << i+1 << ": " << answer << endl;
	}
	return 0;
}
