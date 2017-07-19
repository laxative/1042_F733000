#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int tower1[200],tower2[200];
int num1,num2,test=1;
int LCS[200][200];
int main() {
	while(cin >> num1 >> num2) {
		if(!num1 && !num2)  break;
		for(int i=1;i<=num1;++i)  cin >> tower1[i];
		for(int i=1;i<=num2;++i)  cin >> tower2[i];
		memset(LCS,0,40000*sizeof(int));
		for(int i=1;i<=num1;++i) {
			for(int j=1;j<=num2;++j) {
				if(tower1[i]==tower2[j])  LCS[i][j] = LCS[i-1][j-1]+1;
				else LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
			}
		}
		cout << "Twin Towers #" << test << endl;
		cout << "Number of Tiles : " << LCS[num1][num2] << endl << endl;
		test++;
	}
	return 0;
}
