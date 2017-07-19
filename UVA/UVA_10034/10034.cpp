#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct set{
	float x;
	float y;
}point[105];
int num,p[105];
struct Dis{
	int from;
	int to;
	float dis;
};
vector<Dis> dis;
vector<Dis>::iterator it;
void cal_dis() {
	float dist;
	for(int i=1;i<=num;++i) {
		for(int j=i+1;j<=num;++j) {
			dist = pow(pow((point[j].y-point[i].y),2) + pow((point[j].x-point[i].x),2),0.5);
			dis.push_back((Dis){i,j,dist});
		}
	}
}
bool cmp(Dis a, Dis b) {
	return a.dis < b.dis;
}
void ini() {
	for(int i=1;i<=num;++i)  p[i] = i;
}
int Find(int x) {
	return (p[x] == x) ? x : (p[x]=Find(p[x]));
}
void Union(int x, int y) {
	p[Find(y)] = Find(x);
}
float MST() {
	dis.clear();
	float ans(0);
	cal_dis();
	ini();
	sort(dis.begin(),dis.end(),cmp);
	for(it=dis.begin();it!=dis.end();it++) {
		if(Find(it->from) != Find(it->to)) {
			Union(it->from, it->to);
			ans += it->dis;
		}
	}
	return ans;
}
int main() {
	int cases;
	cin >> cases;
	cout << fixed << setprecision(2);
	while(cases--) {
		cin >> num;
		for(int i=1;i<=num;++i) {
			cin >> point[i].x >> point[i].y;
		}
		cout << MST() << endl;
		if(cases) cout << endl;
	}
	return 0;
}
