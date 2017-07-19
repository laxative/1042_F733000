#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int lines[100000], num;
	cin >> num;
	for(int i=0;i<num;i++) {
		cin >> lines[i];
	}
	sort(lines,lines+num);
	char tmp[4]; cin >> tmp;
	int answer, temp;	
	cin >> answer;
	for(int i=0;i<answer;i++) {
		cin >> temp;
		cout << lines[temp-1] << endl;
	}
	return 0;
}
