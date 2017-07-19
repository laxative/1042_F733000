#include<iostream>
using namespace std;
int main() {
	int n=1, num;
	while(cin >> num) {
		if(!num) break;
		cout << "Case " << n++ << ": " << num/2 << endl;
	}
	return 0;
}
