#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int Case;	scanf("%d",&Case);
	int a;
	string input[100000], out[100000];
	map<char, char>	phone;
	phone['A'] = '2';	phone['B'] = '2';	phone['C'] = '2';
	phone['D'] = '3';	phone['E'] = '3';	phone['F'] = '3';
	phone['G'] = '4';	phone['H'] = '4';	phone['I'] = '4';
	phone['J'] = '5';	phone['K'] = '5';	phone['L'] = '5';
	phone['M'] = '6';	phone['N'] = '6';	phone['O'] = '6';
	phone['P'] = '7';	phone['R'] = '7';	phone['S'] = '7';
	phone['T'] = '8';	phone['U'] = '8';	phone['V'] = '8';
	phone['W'] = '9';	phone['X'] = '9';	phone['Y'] = '9';
	for(int n=0;n<Case;n++) {
		cin >> input[n];
		a=0;
		for(int i=0;i<input[n].length();i++) {
			if(input[n][i] >= 'A' && input[n][i] <= 'Z') {
				out[n] += phone[input[n][i]];
			}else if(input[n][i] <= '9' && input[n][i] >= '0') {
				out[n] += input[n][i];
			}else	continue;
		}
	}
	sort(out,out+Case);
	int count, front(0);
	bool flag(false);
	for(int i=0;i<Case;i++) {
		count = 0;
		while(out[front] == out[i])	{count++;	i++;}
		if(count > 1) {
			for(int j=0;j<out[i].length();j++) {
				if(j==3)	printf("-");
				printf("%c",out[i][j]);
			}
			printf(" %d\n",count);
			flag = true;
			front = i+1;
		}else 		front++;
	}
	if(!flag)		printf("No duplicates\n");
	return 0;
}
