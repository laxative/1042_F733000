#include<iostream>
#include<cstring>
using namespace std;
int save[100000],cal[100000];
int main() {
	int n,temp,Nmax;
	while(cin >> n) {
		if(!n) break;
		memset(cal,0,100000*sizeof(int));
		for(int i=0;i<n;++i)  cin >> save[i];
		cal[0] = save[0]>0?save[0]:0;
		Nmax = cal[0];
		for(int i=1;i<n;++i) {
			cal[i] = cal[i-1]+save[i]>0?cal[i-1]+save[i]:0;
			if(cal[i]>Nmax) Nmax = cal[i];
		}
		if(Nmax) cout << "The maximum winning streak is " << Nmax << "." << endl;
		else cout << "Losing streak." << endl;
	}
	return 0;
}
