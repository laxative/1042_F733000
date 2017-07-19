#include<iostream>
using namespace std; 
long long int dp[7490] = {0};
const int vk[5] = {1,5,10,25,50};
int main() {
	dp[0] = 1;
	for(int i=0;i<5;i++) {
		for(int j=1;j<7490;j++) {
			if(dp[j-vk[i]] && j-vk[i] >= 0)  dp[j] += dp[j-vk[i]];
		}
	}
	int input;
	while(cin >> input)  cout << dp[input] << endl;
	return 0;
}
