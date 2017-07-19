#include<iostream> 
#define MOD 1000000
using namespace std;
long long int C[201][201] = {0};
int N,K;
int main() {
	C[0][0]=1;
	for(int i=1;i<=200;i++) {
		C[i][0] = 1;
		for(int j=1;j<=i;j++) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
		}
	}
	while(cin >> N >> K) {
		if(!N && !K) break;
		cout << C[N+K-1][K-1] << endl;
	}
	return 0;
}
