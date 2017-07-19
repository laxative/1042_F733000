#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;
vector<int> save,length(100000);
int tempmax,m;
int main() {
	int temp,test=1;
	while(1) {
		fill(length.begin(),length.begin()+100000,1);
		cin >> temp;
		if(temp==-1) break;
		save.push_back(temp);
		while(cin >> temp) {
			if(temp==-1) break;
			save.push_back(temp);
		}
		m = 1;
		for(int i=0;i<save.size();i++) {
			tempmax = 0;
			for(int j=0;j<i;j++) {
				if(save[j]>=save[i]) {
					if(length[i] <= length[j]) {
						length[i] += 1;
						tempmax = length[i];
					}
				}
				if(tempmax > m) m = tempmax;
			}
		}
		if(test!=1) cout << endl;
		cout << "Test #" << test << ":" << endl;
		cout << "  maximum possible interceptions: " << m << endl;
		test++;
		save.clear();
	}
	return 0;
}
