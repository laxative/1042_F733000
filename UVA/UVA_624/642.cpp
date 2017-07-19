#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct dictionary {
	string in;
	int hash;
}dic[1000];

bool cmp(dictionary a, dictionary b) {
	return a.in <= b.in;
}
int main() {
	string str;
	int i, compare;
	bool check;
	for(i=0;cin >> str && str != "XXXXXX";i++) {
		dic[i].hash = 0;
		dic[i].in = str;
		for(int j=0;j<str.length();j++) {
			dic[i].hash += 22*str[j] + 24*str[j]*str[j] + 50;
		}
	}
	
	sort(dic,dic+i,cmp);

	for(int n=0;cin >> str && str != "XXXXXX";i++) {
		compare = 0;
		check = false;
		for(int j=0;j<str.length();j++) {
			compare += 22*str[j] + 24*str[j]*str[j] + 50;
		}
		for(int k=0;k<i;k++) {
			if(dic[k].hash == compare)	{
				cout << dic[k].in << endl;
				check = true;
			}
		}
		if(!check) cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
	return 0;
}
