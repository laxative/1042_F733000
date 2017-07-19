#include<iostream>
#include<string>
using namespace std;
int arr1[300] = {0}, arr2[300] = {0},	ans[600] = {0};
int main() {
	int temp, nozero;
	string str1, str2;
	while(cin >> str1 >> str2) {
		for(int i=0;i<600;i++) {
			if(i<300) {
				arr1[i] = 0;
				arr2[i] = 0;
			}
			ans[i] = 0;
		}
		for(int i=str1.length()-1;i>=0;i--) {
			arr1[str1.length()-1-i] = str1[i] - '0';
		}
		for(int i=str2.length()-1;i>=0;--i) {
			arr2[str2.length()-1-i] = str2[i] - '0';
		}
		for(int i=0;i<300;i++) {
			for(int j=0;j<300;j++) {
				ans[i+j] += arr1[i] * arr2[j];
			}
		}
		for(int i=0;i<600;i++) {
			while(ans[i] >= 10) {
				temp = ans[i] / 10;
				ans[i] %= 10;
				ans[i+1] += temp;
			}
		}
		nozero = 599;
		while(nozero >= 1 && ans[nozero] == 0)	nozero--;
		for(int i=nozero;i>=0;i--)	cout << ans[i];
		cout << endl;
	}
	return 0;
}
