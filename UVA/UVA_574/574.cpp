#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int sum,num,temp=0, numAns=0;
int save[1000],tempans[1000];
vector<int> ans[100000];
bool used[1000] = {false};
void backtracking(int start, int s, int count) {
	if(s == sum) {
		for(int i=0;i<num;i++) ans[numAns].push_back(tempans[i]);
		numAns++;
		return;
	} 
	for(int i=start;i<num;i++) {
		if(used[i])  continue;
		if(temp+save[i]<=sum) {
			used[i]=true;
			tempans[count] = save[i];
			temp += tempans[count];
			backtracking(i+1,temp,count+1);
			temp -= tempans[count];
			tempans[count] = 0;
			used[i]=false;
		}
	}
	return;
}
bool cmp(vector<int> a, vector<int> b) {
	if(a.size()==b.size()) {
		for(int i=0;i<a.size();i++) {
			if(a[i]==b[i]) continue;
			return a[i]>b[i];
		}
	}
	return a.size() < b.size();
}
int main() {
	while(cin >> sum >> num) {
		if(!sum && !num) break;
		for(int i=0;i<num;i++) {
			cin >> save[i];
			used[i] = false;
		}
		cout << "Sums of " << sum << ":" << endl;
		backtracking(0,0,0);
		sort(ans,ans+numAns,cmp);
		if(!numAns) cout << "NONE" << endl;
		else{
			for(int i=0;i<numAns;i++) {
				if(ans[i]!=ans[i+1]) {
					for(int j=0;j<ans[i].size();j++) {
						if(!ans[i][j]) break;
						if(j) cout << "+";
						cout << ans[i][j];
					}
					cout << endl;
				}
			}
		}
		for(int i=0;i<numAns;i++) ans[i].clear();
		numAns=0;
	}
	return 0;
}
