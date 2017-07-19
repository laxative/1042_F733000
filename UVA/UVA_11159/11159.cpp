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
	int cases,n,m;
	cin >> cases;
	for(int a=1;a<=cases;a++) {
		cin >> n;
		for(int i=0;i<n;++i) cin >> first[i];
		cin >> m;
		for(int i=0;i<m;++i) cin >> second[i];
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				if(first[i]==0&&second[j]==0 || first[i]!=0 && second[j] % first[i] == 0)  edge[i][j]=true;
				else edge[i][j]=false;
			}
		}
		cout << "Case " << a << ": " << bp(n,m) << endl;
	}
	return 0;
}
