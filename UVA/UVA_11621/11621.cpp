#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long int llt;
int main() {
	vector<llt> v;
	for(int i=0;i<32;i++) {
		for(int j=0;j<32;j++) {
			v.push_back(static_cast<llt>(pow(2,i)*pow(3,j)));
		}
	}
	sort(v.begin(),v.end());
	int a;
	vector<llt>::iterator it;
	while(cin >> a) {
		if(a==0) break;
		for(it=v.begin();it!=v.end();it++) {
			if(a<=*it) {
				cout << *it << endl;
				break;
			}
		}
	}
	return 0;
}
