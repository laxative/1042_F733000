#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int prime[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
int ans[20] = {0};
int num;
bool isPrime(int a) {
	for(int i=0;i<12;i++) {
		if(prime[i] == a) return true;
	}
	return false;
} 
void backtracking(int a, bool *used) {
	if(a==num) {
		if(!isPrime(ans[num-1]+1))  return;
		cout << ans[0];
		for(int i=1;i<num;i++) {
			cout << " " << ans[i];
		}
		cout << endl;
		return;
	}
	for(int i=2;i<=num;i++) {
		if(used[i]) continue;
		if(isPrime(i+ans[a-1])) {
			ans[a] = i;
			used[i] = true;
			backtracking(a+1,used);
			used[i] = false;
		}
	}
	return;
}
int main() {
	int time=1;
	while(cin >> num) {
		if(time!=1) cout << endl;
		memset(ans,0,16*sizeof(int));
		ans[0] = 1;
		bool used[20] = {false};
		used[1] = true;
		cout << "Case " << time << ":" << endl;
		backtracking(1,used);
		time++;
	}
	return 0;
}
