#include<iostream>
#include<algorithm>
using namespace std;
int input[10000] = {0};
int gcd(int a, int b) {
	if(a == 1 || b == 1)	return 1;
	else{
		if(a == 0)	return b;
		else	return gcd(b%a,a);
	}
}
int gcd_min(int num) {
	if(num == 1)	return 1;
	else if(num == 2) return input[1];
	int min = 100000000;
	for(int i=1;i<num;i++) {
		for(int j=i+1;j<num;j++) {
			if(gcd(input[i],input[j]) < min)	min = gcd(input[i],input[j]);
		}
	}
	return min;
}
int main() {
	int i, chk;
	while(1) {
		for(int j=0;j<10000;j++)	input[j] = 0;
		cin >> chk;
		if(chk == 0)	break;
		input[0] = chk;
		for(i=1;i<10000;i++) {
			cin >> chk;
			if(chk == 0)	break;
			else	input[i] = chk;
		}
		sort(input,input+i);
		for(int j=1;j<i;j++)	{
			input[j] -= input[0];
		}
		cout << gcd_min(i) << endl;
	}
	return 0;
}
