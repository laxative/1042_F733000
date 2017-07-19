#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	double cash[12];
	for(int i=0;i<12;i++) {
		cin >> cash[i];
	}
	double sum = 0;
	for(int i=0;i<12;i++) {
		sum += cash[i];
	}
	cout << fixed << setprecision(2);
	cout << "$" << sum/12 << endl;
	return 0;
}
