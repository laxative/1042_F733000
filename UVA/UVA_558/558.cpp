#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Edge{
	int from;
	int to;
	int dist;
};
int dis[10000];
const int INF = 9999999;
vector<Edge> edge;
int n,m;
void BF() {
	for(int i=1;i<10000;++i) dis[i] = INF;
	dis[0] = 0;
	for(int i=0;i<n-1;++i) {
		for(int j=0;j<m;++j) {
			dis[edge[j].to] = min(dis[edge[j].from]+edge[j].dist,dis[edge[j].to]);
		}
	}
	for(int i=0;i<m;++i) {
		if(dis[edge[i].from] + edge[i].dist < dis[edge[i].to]) {
			cout << "possible" << endl;
			return;
		}
	}
	cout << "not possible" << endl;
	return;
}
int main() {
	int cases;
	cin >> cases;
	int a,b,c;
	while(cases--) {
		edge.clear();
		cin >> n >> m;
		for(int i=0;i<m;++i) {
			cin >> a >> b >> c;
			edge.push_back((Edge){a,b,c});
		}
		BF();
	}
	return 0;
}
