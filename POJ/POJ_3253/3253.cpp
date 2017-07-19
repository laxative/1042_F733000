#include<iostream>
#include<queue>
typedef long long int llt;
using namespace std;
int main() {
	llt planks, length, in;
	llt temp;
	priority_queue<llt,vector<llt>,greater<llt> > pq;
	while(cin >> planks) {
		for(int i=0;i<planks;i++) {
			cin >> in;
			pq.push(in);
		}
		length = 0;
		while(pq.size() > 1) {
			temp = pq.top();
			pq.pop();
			temp += pq.top();
			pq.pop();
	
			length += temp;
			pq.push(temp);
		}
		pq.pop();
		if(planks == 1)		cout << in << endl;
		else	cout << length << endl;
	}
	return 0;
}
