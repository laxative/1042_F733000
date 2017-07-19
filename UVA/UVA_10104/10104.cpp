#include<iostream>
using namespace std;
int X,Y;
int exGCD(int a, int b) {
	if(b==0) {
		X = 1;
		Y = 0;
		return a;
	}else {
		int gcd = exGCD(b,a%b);
		int tmp = X;
		X = Y;
		Y = tmp - (a/b)*Y;
		return gcd;
	}
}
int main() {
	int a,b;
	while(cin >> a >> b) {
		cout << X << " " << Y << " " << exGCD(a,b) << endl;
	}
	return 0;
}
