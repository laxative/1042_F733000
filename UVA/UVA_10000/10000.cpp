#include<iostream>
#include<vector>
#include<cmath>
#define INF 9999999
using namespace std;
struct Edge{
	int a;
	int b;
};
vector<Edge> edge;
int dis[10005];
int n,m;
int BF() {
	for(int i=1;i<10005;++i) dis[i] = INF;
	dis[m] = 0;
	int p,q;
	for(int i=0;i<n-1;++i) {
		for(int j=0;j<edge.size();++j) {
			p = edge[j].a;
			q = edge[j].b;
			if(dis[p]-1<dis[q]) {
				dis[q] = dis[p] - 1;
			}
		}
	}
	int min = 0, ans;
	for(int i=1;i<=n;++i) {
		if(min > dis[i]) {
			min = dis[i];
			ans = i;
		}
	}
	return ans;
}
int main() {
	int cases = 1;
	while(cin >> n) {
		if(!n) break;
		cin >> m;
		edge.clear();
		int a,b;
		while(cin >> a >> b) {
			if(a==0 && b==0) break;
			edge.push_back((Edge){a,b});
		}
		int finish = BF();
		cout << "Case " << cases++ << ": The longest path from " << m;
		cout << " has length " << abs(dis[finish]) << ", finishing at " << finish << "." << endl << endl;
	}
	return 0;
}
