#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 6000;
const int N = 600;
int n,m,w;
struct Edge{
	int from;
	int to;
	int dist;
};
vector<Edge> edge;

int vis[N];
void addedge(int from, int to, int dist) {
	edge.push_back((Edge){from, to, dist});
}
void BF() {
	int a,b,c;
	for(int i=1;i<N;++i) vis[i] = INF;
	vis[0] = 0;
	for(int i=0;i<n-1;++i) {
		for(int j=0;j<edge.size();++j) {
			a = edge[j].from;
			b = edge[j].to;
			c = edge[j].dist;
			if(vis[a] + c < vis[b]) {
				vis[b] = vis[a] + c;
			}
		}
	}
	for(int i=0;i<edge.size();++i) {
		a = edge[i].from;
		b = edge[i].to;
		c = edge[i].dist;
		if(vis[a] + c < vis[b]) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}
int main() {
	int Cases;
	cin >> Cases;
	int a,b,c;
	while(Cases--) {
		edge.clear();
		cin >> n >> m >> w;
		for(int i=0;i<m;++i) {
			cin >> a >> b >> c;
			addedge(a,b,c);
			addedge(b,a,c);
		}
		for(int i=0;i<w;++i) {
			cin >> a >> b >> c;
			addedge(a,b,-c);
		}
		BF();
	}
	return 0;
}
