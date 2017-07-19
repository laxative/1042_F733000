#include<iostream>
#include<string>
using namespace std;
int num[20], num2[20], ans[20];
int main() {
	string str1, str2;
	int count;
	while(cin >> str1 >> str2) {
		for(int i=0;i<20;i++) {
			num[i] = 0;
			num2[i] = 0;
			ans[i] = 0;
		}
		count = 0;
		if(str1 == "0" && str2 == "0")	break;
		for(int i=0;i<str1.length();i++)	num[str1.length()-i-1] = str1[i] - '0';
		for(int i=0;i<str2.length();i++)	num2[str2.length()-i-1] = str2[i] - '0';

		for(int i=0;i<20;i++) {
			ans[i] += (num[i] + num2[i]);
			if(ans[i]>=10) {
				count++;
				ans[i+1] += ans[i] / 10;
			}
		}

		if(count==0)	cout << "No carry operation." << endl;
		else if(count==1)	cout << count << " carry operation." << endl;
		else	cout << count << " carry operations." << endl;
	}
	return 0;
}
