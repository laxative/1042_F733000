#include<iostream>
#include<string>
using namespace std;
int pre[1000010];
void fail(string in) {
	pre[0] = -1;
	for(int i=1,j=-1;i<in.length();++i) {
		while(j>=0 && in[i]!=in[j+1])
			j = pre[j];
		if(in[i]==in[j+1]) ++j;
		pre[i] = j;
	}
	int t=in.length()-1-pre[in.length()-1];
	if(t==0) cout << 1 << endl;
	else if(in.length()%t==0) cout << in.length()/t << endl;
	else cout << 1 << endl;
}
int main() {
	string in;
	while(cin >> in) {
		if(in==".")  break;
		fail(in);
	}
	return 0;
}
