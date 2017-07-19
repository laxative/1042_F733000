#include<iostream>
#include<string>
using namespace std;
void transchar(string str);
int main() {
	string check, str;
	while(getline(cin,check)) {
		if(check == "ENDOFINPUT") {
			break;
		}else if(check == "START") {
			getline(cin,str);
			transchar(str);
		}
	}
	return 0;
}
void transchar(string str) {
	for(int i=0;i<str.length();i++) {
		if(str[i]>='A' && str[i]<='E') {
			str[i] += 21;
		}else if(str[i]>='F' && str[i] <= 'Z') {
			str[i] -= 5;
		}
	}
	cout << str << endl;
}
