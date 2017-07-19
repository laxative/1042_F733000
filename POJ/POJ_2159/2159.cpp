#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void compare(string input, string check);
int main() {
	string input, check;
	getline(cin,input);
	getline(cin,check);
	compare(input, check);
	return 0;
}
void compare(string input, string check) {
	int input_char[26]={0}, check_char[26]={0};
	int temp;
	for(int i=0;i<input.length();i++) {
		if(input[i]>='A' && input[i]<='Z') {
			temp = input[i] - 'A';
			input_char[temp]++;
		}
	}
	for(int i=0;i<check.length();i++) {
		if(check[i]>='A' && check[i]<='Z') {
			temp = check[i] - 'A';
			check_char[temp]++;
		}
	}
	sort(input_char, input_char + 26);
	sort(check_char, check_char + 26);
	bool chk(true);
	for(int i=0;i<26;i++) {
		if(input_char[i]!=check_char[i]) {
			chk = false;
			break;
		}
	}
	if(chk) {
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
