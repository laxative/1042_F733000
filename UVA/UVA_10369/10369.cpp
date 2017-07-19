#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
struct point{
	int x;
	int y;
}point[501];
int p[501];
int s,num;
struct edge{
	int from;
	int to;
	float dis;
};
vector<edge> E;
vector<edge>::iterator it;
vector<float> dist;
void ini() {
	for(int i=1;i<=num;++i)  p[i] = i;
}
//disjoint set
int Find(int x) {
	return (p[x]==x)? x : Find(p[x]);
}
void Union(int x, int y) {
	p[Find(y)] = Find(x);
}
//calc the distance between the points
void cal() {
	float dist;
	for(int i=1;i<=num;++i) {
		for(int j=i+1;j<=num;++j) {
			dist = pow(pow((point[j].y-point[i].y),2) + pow((point[j].x-point[i].x),2),0.5);
			E.push_back((edge){i,j,dist});
		}
	}
}
bool cmp(edge a, edge b) {
	return a.dis < b.dis;
}
float MST() {
	E.clear();
	cal();
	ini();
	dist.clear();
	sort(E.begin(),E.end(),cmp);
	for(it=E.begin();it!=E.end();it++) {
		if(Find(it->from)!=Find(it->to)) {
			Union(it->from,it->to);
			dist.push_back(it->dis);
		}
	}
	//to find the min of network => the sort edge size - s's num
	return dist[dist.size()-s];
}
int main() {
	int cases;
	cin >> cases;
	while(cases--) {
		cin >> s >> num;
		for(int i=1;i<=num;++i) {
			cin >> point[i].x >> point[i].y;
		}
		cout << fixed << setprecision(2);
		cout << MST() << endl;
	}
	return 0;
}
