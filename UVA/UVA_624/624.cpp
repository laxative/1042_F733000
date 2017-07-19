#include<iostream>
#include<vector>
using namespace std;
int sum,num,tmp=0,Max;
int save[1000000];
vector<int> ans,temp;
void backtracking(int begin, int s) {
	if(s > Max) {
		ans = temp;
		Max = s;
	} 
	for(int i=begin;i<num;i++) {
		if(s+save[i]<=sum) {
			temp.push_back(save[i]);
			backtracking(i+1,s+save[i]);
			temp.pop_back();
		}
	}
	return;
}
int main() {
	while(cin >> sum >> num) {
		Max = 0;
		for(int i=0;i<num;i++) cin >> save[i];
		backtracking(0,0);
		int Sum=0;
		for(int n:ans) {
			cout << n << " ";
			Sum += n;
		}
		cout << "sum:" << Sum << endl;
		temp.clear();
		ans.clear();
	}
	return 0;
}
