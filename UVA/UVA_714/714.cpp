#include<iostream>
using namespace std;
int main() {
	int a,b,Case;
	int book[1000];
	cin >> Case;
	while(Case--) {
		cin >> a >> b;
		for(int i=0;i<a;i++) {
			cin >> book[i];
		}
	}
	return 0;
}
