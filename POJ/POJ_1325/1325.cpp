#include<iostream>
#include<cstring>
using namespace std;
int llink[110], rlink[110];
bool used[110], edge[110][110];
int first[110], second[110];
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
	int n,m,k;
	int a,x,y;
	while(cin >> n) {
		if(!n) break;
		memset(edge,false,sizeof(edge));
		cin >> m >> k;
		for(int i=0;i<k;++i) {
			cin >> a >> x >> y;
			if(!x || !y) continue;
			edge[x][y]=true;
		}
		cout << bp(n,m) << endl;
	}
	return 0;
}
