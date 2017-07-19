#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int p[101],num,line;
struct edge{
	int from;
	int to;
	int dis;
};
vector<edge> E;
vector<edge>::iterator it;
vector<int> ans;
//disjoint set
void ini() {
	for(int i=0;i<num;++i) p[i] = i;
}
int Find(int x) {
	return (p[x]==x) ? x : (p[x] = Find(p[x]));
}
void Union(int x, int y) {
	p[Find(y)] = Find(x);
}
//end disjoint set
//
//to find the maximum spanning tree
bool cmp(edge a, edge b) {
	return a.dis > b.dis;
}
//Kruskal’s Algorithm
int MST() {
	ans.clear();
	ini();
	sort(E.begin(),E.end(),cmp);
	for(it=E.begin();it!=E.end();it++) {
		if(Find(it->from)!=Find(it->to)) {
			Union(it->from,it->to);
			ans.push_back(it->dis);
		}
	}
	return ans[ans.size()-1];
}
//end
int main() {
	int n=1,cases;
	cin >> cases;
	int a,b,c;
	while(cases--) {
		E.clear();
		cin >> num >> line;
		for(int i=0;i<line;++i) {
			cin >> a >> b >> c;
			E.push_back((edge){a,b,c});
			E.push_back((edge){b,a,c});
		}
		cout << "Case #" << n++ << ": " << MST() << endl;
	}
	return 0;
}
