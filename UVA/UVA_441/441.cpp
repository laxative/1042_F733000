#include<iostream>
#include<algorithm>
using namespace std; 
int store[49], solution[6];
int k;
bool used[49];
void backtracking(int x) {
	if(x==6) {
		cout << solution[0];
		for(int i=1;i<6;i++) {
			cout << " " << solution[i];
		}
		cout << endl;
		return;
	}
	for(int i=0;i<k;++i) {
		if(!used[i] && store[i] > solution[x-1]) {
			solution[x] = store[i];
			used[i] = true;
			backtracking(x+1);
			used[i] = false;
		}
	}
}
int main() {
	int ct = 0;
	while(cin >> k) {
		if(!k)  break;
		for(int i=0;i<k;i++) {
			cin >> store[i];
			used[i] = false;
		}
		sort(store,store+k);
		if(ct++) cout << endl;
		backtracking(0);
	}
	return 0;
}
