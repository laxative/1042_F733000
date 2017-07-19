#include<iostream>
#include<string>
#include<algorithm>
#define max 100
using namespace std;
int main() {
	string dic[max], out[max], temp;
	int i(0), num(0);
	//put volcabulary into dictionary
	while(cin >> temp) {
		if(temp == "XXXXXX") break;	
		dic[i] = temp;
		i++;	num++;
		sort(dic,dic+i);  //sort can arrange string, first arrange by length, next arrange by ASCII code
	}
	//arrange
	for(i=0;i<num;i++) {
		out[i] = dic[i];
		sort(dic[i].begin(),dic[i].end());
	}
	//to find
	while(cin >> temp) {
		if(temp == "XXXXXX")	break;
		int flag(0);
		sort(temp.begin(),temp.end());
		for(int j=0;j<num;j++) {
			if(dic[j] == temp) {
				cout << out[j] << endl;
				flag = 1;
			}
		}
		if(!flag) {
			cout << "NOT A VALID WORD" << endl;
		}
		cout << "******" << endl;
	}
	return 0;
}
