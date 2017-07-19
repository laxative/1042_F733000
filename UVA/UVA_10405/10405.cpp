#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	string input[2];
	while(getline(cin,input[0])) {
		getline(cin,input[1]);
		int LCS[1001][1001] = {0};
		for(int i=1;i<=input[0].length();++i) {
			for(int j=1;j<=input[1].length();++j) {
				if(input[0][i-1] == input[1][j-1]) LCS[i][j] = LCS[i-1][j-1]+1;
				else LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
			}
		}
		cout << LCS[input[0].length()][input[1].length()] << endl;
	}
	return 0;
}
