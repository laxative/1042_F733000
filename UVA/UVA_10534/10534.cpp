#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int save[100000];
vector<int> LIS(100000),LDS(100000);
vector<int> temp;
vector<int>::iterator l;
int Max,cnt;
int main() {
	int num;
	while(cin >> num) {
		Max = 0;
		fill(LIS.begin(),LIS.begin()+100000,0);
		fill(LDS.begin(),LDS.begin()+100000,0);
		for(int i=0;i<num;i++)   cin >> save[i];
		temp.push_back(save[0]);
		//LIS
		cnt=1;
		for(int i=1;i<num;i++) {
			l = lower_bound(temp.begin(),temp.end(),save[i]);
			int pos = l - temp.begin();
			if(pos==temp.size()) {
				temp.push_back(save[i]);
				LIS[i] = cnt++;
			}else{
				*l = save[i];
				LIS[i] = pos;
			}
		}
		temp.clear();
		temp.push_back(save[num-1]);
		cnt=1;
		for(int i=num-2;i>=0;i--) {
			l = lower_bound(temp.begin(),temp.end(),save[i]);
			int pos = l - temp.begin();
			if(pos==temp.size()) {
				temp.push_back(save[i]);
				LDS[i] = cnt++;
			}else{
				*l = save[i];
				LDS[i] = pos;
			}
		}
		for(int i=0;i<num;i++) {
			if(Max < min(LIS[i],LDS[i])) Max = min(LIS[i],LDS[i]);
		}
		cout << Max*2+1 << endl;
		temp.clear();
	}
	return 0;
}
