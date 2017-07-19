#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int llink[110], rlink[110];
bool used[110], edge[110][110];
struct point{
	double x;
	double y;
}gopher[110],hole[110];
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
	int n,m,s,v;
	while(cin >> n >> m >> s >> v) {
		for(int i=0;i<n;++i)  cin >> gopher[i].x >> gopher[i].y;
		for(int i=0;i<m;++i)  cin >> hole[i].x >> hole[i].y;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				double dis=sqrt(pow((hole[j].x-gopher[i].x),2) + pow((hole[j].y-gopher[i].y),2));
				if(dis/v <= s) edge[i][j] = true;
				else edge[i][j] = false;
			}
		}
		cout << n-bp(n,m) << endl;
	}
	return 0;
}
