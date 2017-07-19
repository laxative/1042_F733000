#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string city[2];
	int Case=1;
	while(getline(cin,city[0]) && city[0]!= "#") {
		getline(cin,city[1]);
		int LCS[200][200] = {0};
		for(int i=1;i<=city[0].length();++i) {
			for(int j=1;j<=city[1].length();++j) {
				if(city[0][i-1]==city[1][j-1]) LCS[i][j] = LCS[i-1][j-1]+1;
				else LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
			}
		}
		cout << "Case #" << Case++ << ": you can visit at most " << LCS[city[0].length()][city[1].length()] << " cities." << endl;
	}
	return 0;
}
