#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int test;		cin >> test;
	string country[test], nothing;
	for(int i=0;i<test;i++) {
		cin >> country[i];
		getline(cin,nothing);
	}
	sort(country,country+test);
	int j, count;
	for(int i=0;i<test;i++) {
		count = 0;
		cout << country[i] << " ";
		for(j=i;j<test;j++) {
			if(country[j] == country[i]) {
				count++;
			}else {
				break;
			}
		}
		cout << count << endl;
		i = j-1;
	}
	return 0;
}
