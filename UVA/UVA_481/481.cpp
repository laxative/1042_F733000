#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> save, tmp;
vector<int>::iterator l;
stack<int> ans;
int pos[100000] = {0};
int main() {
	int temp, numCount=1;
	while(cin >> temp) {
		save.push_back(temp);
	}
	tmp.push_back(save[0]);
	for(int i=1;i<save.size();i++) {
		l = lower_bound(tmp.begin(),tmp.end(),save[i]);
		int Pos = l-tmp.begin();
		if(Pos==tmp.size()) {
			tmp.push_back(save[i]);
			pos[i] = numCount++;
		}else{
			*l = save[i];
			pos[i] = Pos;
		}
	}
	for(int i=save.size()-1;i>=0;i--){
		if(pos[i]==numCount-1) {
			ans.push(save[i]);
			numCount--;
		}
	}
	cout << ans.size() << endl << "-" << endl;
	while(!ans.empty()){
		cout << ans.top() << endl;
		ans.pop();
	}
	return 0;
}
