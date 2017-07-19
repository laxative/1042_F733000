#include<iostream>
#include<cstring>
using namespace std;
int llink[501], rlink[501];
bool used[501], edge[501][501];
bool DFS(int cur,const int m) {
	for(int next=0;next<m;++next) {
		if(edge[cur][next]==false || used[next]) continue;
		used[next]=true;
		if(rlink[next]==-1 || DFS(rlink[next],m)) {
			rlink[next]=cur;
			llink[cur]=next;
			return true;
		}
	}
	return false;
}
int bp(int L,int m) {
	int ret=0;
	memset(llink,-1,sizeof(llink));
	memset(rlink,-1,sizeof(rlink));
	for(int i=0;i<L;++i) {
		memset(used,false,sizeof(used));
		if(DFS(i,m)) ret++;
	}
	return ret;
}
int main() {
	int size, cases;
	cin >> size >> cases;
	int a,b;
	memset(edge,false,sizeof(edge));
	for(int i=0;i<cases;++i) {
		cin >> a >> b;
		edge[a][b]=true;
	}
	cout << bp(size+1,size+1) << endl;
	return 0;
}
