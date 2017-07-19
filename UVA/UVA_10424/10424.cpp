#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
void trans(string name1, string name2) {
	int i;
	int num_name1=0, num_name2=0;
	for(i=0;i<name1.length();i++) {
		if(name1[i]>='a' && name1[i]<='z') {
			num_name1 += (name1[i] - 'a' + 1);
		}else if(name1[i]>='A' && name1[i]<='Z'){
			num_name1 += (name1[i] - 'A' + 1);
		}
	}
	for(i=0;i<name2.length();i++) {
		if(name2[i]>='a' && name2[i]<='z') {
			num_name2 += (name2[i] - 'a' + 1);
		}else if(name2[i]>='A' && name2[i]<='Z'){
			num_name2 += (name2[i] - 'A' + 1);
		}
	}
	while(num_name1>=10 || num_name2 >=10) {
		num_name1 = num_name1 / 10 + num_name1 % 10;
		num_name2 = num_name2 / 10 + num_name2 % 10;
	}
	cout << fixed << setprecision(2);
	float answer;
	if(num_name1 == 0 && num_name2 == 0) {
		cout << endl;
	}else if(num_name1 == 0 || num_name2 == 0) {
		cout << "0.00 %" << endl;
	}else if(num_name1 > num_name2) {
		answer = num_name2 / static_cast<double>(num_name1) * 100;
		cout << answer << " %" << endl;
	}else {
		answer = num_name1 / static_cast<double>(num_name2) * 100;
		cout << answer << " %" << endl;
	}
}
int main() {
	string name1, name2;
	while(getline(cin,name1)) {
		getline(cin,name2);
		trans(name1,name2);
	}
	return 0;
}
