#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int cows;
	cin >> cows;
	long long milk[cows];
	for(int i=0;i<cows;i++) {
		cin >> milk[i];
	}
	sort(milk,milk+cows);
	cout << milk[cows/2] << endl;
	return 0;
}
