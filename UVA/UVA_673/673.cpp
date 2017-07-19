#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main() {
	int Case;
	scanf("%d%*c",&Case);
	stack<char>	input;
	char ch;
	for(int i=0;i<Case;i++) {
		while(1) {
			ch = getchar();
			if(ch == '\n')	break;
			else if(input.empty())	input.push(ch);
			else {
				switch(input.top()) {
					case '(':
						if(ch == ')')	input.pop();
						else	input.push(ch);
						break;
					case '[':
						if(ch == ']')	input.pop();
						else	input.push(ch);
						break;
					case ')':
						input.push(ch);
						break;
					case ']':
						input.push(ch);
						break;
					default:
						break;
				}
			}
		}
		if(input.empty())	cout << "Yes" << endl;
		else	cout << "No" << endl;
		while(!input.empty()) {
			input.pop();
		}
	}
	return 0;
}
