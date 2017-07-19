#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 99999999
using namespace std;
int from,to,num;
int cap[50][50], flow[50][50];
int pre[50];
bool visited[50];
bool DFS(int from, int to, int num) {
	visited[from] = true;
	if(from==to) return true;
	for(int i=1;i<=num;++i) {
		if(visited[i]) continue;
		if(cap[from][i]-flow[from][i]>0 || flow[i][from]>0) {
			pre[i] = from;
			if(DFS(i,to,num)) return true;
		}
	}
	return false;
}
int findflow(int from, int to) {
	int p, f=INF;
	for(int i=to;i!=from;i=pre[i]) {
		p = pre[i];
		if(cap[p][i]-flow[p][i]>0) {
			f=min(f,cap[p][i]-flow[p][i]);
		} else {
			f=min(f,flow[i][p]);
		}
	}
	for(int i=to;i!=from;i=pre[i]) {
		p = pre[i];
		if(cap[p][i]-flow[p][i]>0) {
			flow[p][i]+=f;
		} else {
			flow[i][p]-=f;
		}
	}
	return f;
}
int maxflow(int num) {
	int res=0;
	while(1) {
		memset(visited,false,sizeof(visited));
		if(!DFS(from,to,num)) break;
		res += findflow(from,to);
	}
	return res;
}
int main() {
	return 0;
}
