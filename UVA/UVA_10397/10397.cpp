#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
#include<iomanip>
using namespace std;
struct point{
	int x;
	int y;
}p[20000];
int group[20000];
struct edge{
	int from;
	int to;
	double dis;
};
vector<edge> e;
vector<edge>::iterator it;
int m,n;
void ini() {
	for(int i=1;i<=n;++i) group[i]=i;
}
int Find(int x) {
	return (group[x]==x) ? x : (group[x] = Find(group[x]));
}
void Union(int x, int y) {
	group[Find(y)] = Find(x);
}
bool cmp(edge a, edge b) {
	return a.dis < b.dis;
}
void calDis() {
	double dis(0);
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			dis = sqrt(pow(p[j].x-p[i].x,2) + pow(p[j].y-p[i].y,2));
			e.push_back((edge){i,j,dis});
		}
	}
	sort(e.begin(),e.end(),cmp);
}
void MST() {
	ini();
	calDis();
	double ans(0);
	for(it=e.begin();it!=e.end();++it) {
		if(Find(it->from)!=Find(it->to)) {
			Union(it->from,it->to);
			ans += it->dis;
		}
	}
	cout << fixed << setprecision(2);
	cout << ans << endl;
}
int main() {
	while(cin >> n) {
		e.clear();
		for(int i=1;i<=n;++i) {
			cin >> p[i].x >> p[i].y;
		}
		cin >> m;
		int a,b;
		while(m--) {
			cin >> a >> b;
			e.push_back((edge){a,b,0});
		}
		MST();
	}
	return 0;
}
