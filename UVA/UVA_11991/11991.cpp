#include<iostream>
#include<vector>
using namespace std;
vector<int> num[1000001];
int input[1000001];
int main() {
	int M,N;
	while(cin >> M >> N) {
		for(int i=0;i<M;i++)	cin >> input[i];
		for(int i=0;i<1000001;i++)	num[i].clear();
		for(int i=0;i<M;i++)	num[input[i]].push_back(i+1);

		int a,b;
		for(int i=0;i<N;i++) {
			cin >> a >> b;
			if(num[b].size() < a)	cout << 0 << endl;
			else	cout << num[b][a-1] << endl;
		}
	}
	return 0;
}
