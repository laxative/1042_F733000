#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int group[801];
struct place{
	float x;
	float y;
}p[801];

int m,n;
struct edge{
	int from;
	int to;
	float dis;
};
vector<edge> E;
vector<edge>::iterator it;
void ini() {
	for(int i=0;i<801;++i) group[i]=i;
}
int Find(int x) {
	return (group[x]==x) ? x : (group[x]=Find(group[x]));
}
void Union(int x, int y) {
	group[Find(y)] = Find(x);
}
bool cmp(edge a, edge b) {
	return a.dis < b.dis;
}
void calDis() {
	float temp;
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;j++) {
			temp = sqrt(pow(p[j].x-p[i].x,2) + pow(p[j].y-p[i].y,2));
			E.push_back((edge){i,j,temp});
		}
	}
	sort(E.begin(),E.end(),cmp);
}
void MST() {
	bool flag=false;
	ini();
	calDis();
	for(it=E.begin();it!=E.end();++it) {
		//cout << it->from << " " << it->to << " " << it->dis << endl;
		if(Find(it->from) != Find(it->to)) {
			Union(it->from,it->to);
			flag=true;
			if(it->dis!=0)
				cout << it->from << " " << it->to << endl;
		}
	}
	if(!flag) cout << "No new highways need" << endl;
	return;
}
int main() {
	int cases;
	cin >> cases;
	while(cases--) {
		E.clear();
		cin >> n;
		for(int i=1;i<=n;++i)  cin >> p[i].x >> p[i].y;
		
		//connect two city
		cin >> m;
		int a,b;
		while(m--) {
			cin >> a >> b;
			E.push_back((edge){min(a,b),max(a,b),0});
		}
		MST();
		if(cases) cout << endl;
	}
	return 0;
}
