#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int time, fine, order;
};
//fector
bool cmp(node a,node b) {
	double r1 = (double)a.fine/a.time;
	double r2 = (double)b.fine/b.time;
	return r1 > r2;
}
node shoemaker[100000];
int main() {
	int test;	cin >> test;
	int num, temp1, temp2;
	for(int i=0;i<test;i++) {
		cin >> num;
		for(int j=0;j<num;j++) {
			cin >> shoemaker[j].time >> shoemaker[j].fine;
			shoemaker[j].order = j + 1;
		}
		sort(shoemaker,shoemaker+num,cmp);
		for(int j=0;j<num;j++) {
			if(j == 0)	cout << shoemaker[j].order;
			else	cout << " " << shoemaker[j].order;
		}
		cout << endl;
		if(i!=test-1)		cout << endl;
	}
	return 0;
}
