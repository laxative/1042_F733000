#include<iostream>
#include<string>
using namespace std;
int pre[1000010];
void fail(int len, string in) {
	pre[0] = -1;
	for(int i=1, cur_pos=-1;i<len;++i) {
		while(cur_pos>=0 && in[i]!=in[cur_pos+1])
			cur_pos = pre[cur_pos];
		if(in[i]==in[cur_pos+1]) ++cur_pos;
		pre[i] = cur_pos;
		if(cur_pos>=0 && (i+1) % (i-cur_pos)==0)
			cout << i+1 << " " << (i+1)/(i-cur_pos) << endl;
	}
	cout << endl;
}
int main() {
	int len,i=0;
	string in;
	while(cin >> len) {
		if(!len) break;
		cin >> in;
		cout << "Test case #" << ++i << endl;
		fail(len,in);
	}
	return 0;
}
