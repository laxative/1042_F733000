#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 99999999
using namespace std;
int cap[205][205], flow[205][205];
int pre[205];
int num, from, to, road;
bool visited[205];
bool DFS(int from, int to, int n) {
	visited[from] = true;
	if(from == to) return true;
	for(int i=1;i<=n;++i) {
		if(visited[i]) continue;
		if(cap[from][i]-flow[from][i]>0 || flow[i][from]>0) {
			pre[i] = from;
			if(DFS(i,to,n)) return true;
		}
	}
	return false;
}
int findflow(int from, int to) {
	int f = INF;
	int Pre;
	for(int i=to;i!=from;i=pre[i]) {
		Pre = pre[i];
		if(cap[Pre][i]-flow[Pre][i]>0) {
			f = min(f,cap[Pre][i]-flow[Pre][i]);
		} else {
			f = min(f,flow[i][Pre]);
		}
	}
	for(int i=to;i!=from;i=pre[i]) {
		Pre = pre[i];
		if(cap[Pre][i]-flow[Pre][i]>0) {
			flow[Pre][i]+=f;
		} else {
			flow[i][Pre]-=f;
		}
	}
	return f;
}
int maxflow(int n) {
	int ans=0;
	while(1) {
		memset(visited,false,sizeof(visited));
		if(!DFS(from,to,n)) break;
		ans+=findflow(from,to);
	}
	return ans;
}
int main() {
	int test=1;
	while(cin >> num) {
		if(num==0) break;
		int a,b,c;
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		cin >> from >> to >> road;
		for(int i=0;i<road;++i) {
			cin >> a >> b >> c;
			cap[a][b] += c;
			cap[b][a] += c;
		}
		cout << "Network " << test++ << endl;
		cout << "The bandwidth is " << maxflow(num) << "." << endl;
		cout << endl;
	}
	return 0;
}
