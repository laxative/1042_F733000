#include<iostream>
using namespace std;

int method(int n) {
	int time = 1;
	while(n != 1) {
		if(n%2!=0) {
			n = 3 * n + 1;
		}else{
			n = n / 2;
		}
	time++;
	}
	return time;
}
int main() {
	int i, j, k;
	while(cin >> i >> j) {
	k = i;
	int time_max(0);
	if(i<=j) {
		while(i<=j) {
			if(time_max < method(i)) {
				time_max = method(i);
			}
			i++;	
		}
		cout << k << " " << j << " " << time_max << endl;
	}else{
		while(i>=j) {
			if(time_max < method(i)) {
				time_max = method(i);
			}
			i--;	
		}
		cout << k << " " << j << " " << time_max << endl;
		}
	time_max = 0;
	}
}
