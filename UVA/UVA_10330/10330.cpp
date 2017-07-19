#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 10000000
using namespace std;
int cap[205][205], flow[205][205];
int vi[205],pa[205];
bool DFS(int s, int t, int n) {
	int i,j,k;
	vi[s] = 1;
	if(s==t) return true;
	for(int i=0;i<n;++i) {
		if(vi[i]) continue;
		if(cap[s][i]-flow[s][i]>0 || flow[i][s]>0) {
			pa[i] = s;
			if(DFS(i,t,n)) return true;
		}
	}
	return false;
}
int FindFlow(int s, int t) {
	int i,pre;
	int f=INF;
	for(i=t;i!=s;i=pa[i]) {
		pre = pa[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f = min(f,cap[pre][i]-flow[pre][i]);
		else f = min(f,flow[i][pre]);
	}
	for(i=t;i!=s;i=pa[i]) {
		pre = pa[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		else flow[i][pre]-=f;
	}
	return f;
}
int maxflow(int n) {
	int i,j,k;
	int ret=0;
	while(1) {
		memset(vi,0,sizeof(vi));
		if(!DFS(0,2*n+1,2*n+2)) break;
		ret += FindFlow(0,2*n+1);
	}
	return ret;
}
int main() {
	int Nodenum,edgeNum,beginNodeNum,endNodeNum,temp,from,to,value;
	while(cin >> Nodenum) {
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		for(int i=1;i<=Nodenum;++i)  cin >> cap[i][i+Nodenum];
		cin >> edgeNum;
		for(int i=0;i<edgeNum;++i) {
			cin >> from >> to >> value;
			cap[from+Nodenum][to] = value;
		}
		cin >> beginNodeNum >> endNodeNum;
		for(int i=0;i<beginNodeNum;++i) {
			cin >> temp;
			cap[0][temp] = INF;
		}
		for(int i=0;i<endNodeNum;++i) {
			cin >> temp;
			cap[temp+Nodenum][2*Nodenum+1] = INF;
		}
		cout << maxflow(Nodenum) << endl;
	}
	return 0;
}
