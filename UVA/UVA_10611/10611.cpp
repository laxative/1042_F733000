#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int> v;
	int inputnum;
	int temp;
	cin >> inputnum;
	for(int i=0;i<inputnum;i++) {
		cin >> temp;
		v.push_back(temp);
	}
	cin >> inputnum;
	vector<int>::iterator low,up;
	for(int i=0;i<inputnum;i++) {
		cin >> temp;
		if(temp>=v[inputnum-1]) cout << v[inputnum-1] << " X" << endl;
		else if(temp<=v[0]) cout << "X " << v[0];
		else {
			low = lower_bound(v.begin(),v.end(),temp);
			up = upper_bound(v.begin(),v.end(),temp);
			cout << *(low-1) << " " << *up << endl;
		}
	}
	return 0;
}
