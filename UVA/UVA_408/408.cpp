#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int step, int mod) {
	if(step == 1 || mod == 1)	return 1;
	else {
		if(step == 0)	return mod;
		return	gcd(mod % step,step);
	}
}
int main() {
	int step, mod;
	int ans;
	while(cin >> step >> mod) {
		ans = gcd(step,mod);
		if(ans == 1)	printf("%10d%10d    Good Choice\n\n",step,mod);
		else		printf("%10d%10d    Bad Choice\n\n",step,mod);
	}
	return 0;
}
