#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {
	double a, b;
	cout << fixed << setprecision(0);
	while(cin >> b >> a)
		cout << pow(a,(1/b)) << endl;
	return 0;
}
