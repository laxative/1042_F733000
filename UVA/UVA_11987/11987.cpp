#include<iostream>
#include<vector>
using namespace std;
int p[10001];
vector<int> v[10001];
vector<int>::iterator it;
void init(int n) {
	for(int i=1;i<=n;++i) {
		p[i] = i;
		v[i].push_back(i);
	}
	return;
}
int Find(int a) {
	return (p[a]==a) ? a : (p[a] = Find(p[a]));
}
void A_oper(int a, int b, int n) {
	bool find;
	int whereA, whereB;
	for(int i=1;i<=n;++i) {
		find = false;
		if(v[i].empty())  continue;
		for(it=v[i].begin();it!=v[i].end();it++) {
			if(*it==a) {
				find = true;
				whereA = i;
				break;
			}
		}
		if(find) break;
	}
	for(int i=1;i<=n;++i) {
		find = false;
		if(v[i].empty())  continue;
		for(it=v[i].begin();it!=v[i].end();it++) {
			if(*it==b) {
				find = true;
				whereB = i;
				break;
			}
		}
		if(find) break;
	}
	for(it=v[whereA].begin();it!=v[whereA].end();it++) {
		v[whereB].push_back(*it);
	}
	v[whereA].clear();
	p[whereA] = Find(whereB);
	return;
}
void B_oper(int a, int b, int n) {
	bool find;
	for(int i=1;i<=n;++i) {
		find = false;
		if(v[i].empty())  continue;
		for(it=v[i].begin();it!=v[i].end();it++) {
			if(*it==a) {
				find = true;
				v[i].erase(it);
				break;
			}
		}
		if(find) break;
	}
	for(int i=1;i<=n;++i) {
		find = false;
		if(v[i].empty())  continue;
		for(it=v[i].begin();it!=v[i].end();it++) {
			if(*it==b) {
				find = true;
				v[i].push_back(a);
				break;
			}
		}
		if(find) break;
	}
	return;
}
void C_oper(int a, int n) {
	bool find;
	int where, num, ans;
	for(int i=1;i<=n;++i) {
		find = false;
		if(v[i].empty())  continue;
		for(it=v[i].begin();it!=v[i].end();it++) {
			if(*it==a) {
				find = true;
				where = i;
				break;
			}
		}
		if(find) break;
	}
	ans = 0;
	num = v[where].size();
	for(it=v[where].begin();it!=v[where].end();it++) {
		ans += *it;
	}
	cout << num << " " << ans << endl;
	return;
}
int main() {
	int num, oper, type;
	while(cin >> num >> oper) {
		init(num);
		int a,b;
		for(int i=0;i<oper;++i) {
			cin >> type;
			switch(type) {
				case 1:
					cin >> a >> b;
					A_oper(a,b,num);
					break;
				case 2:
					cin >> a >> b;
					B_oper(a,b,num);
					break;
				case 3:
					cin >> a;
					C_oper(a,num);
					break;
				default:
					break;
			}
		}
	}
	return 0;
}
