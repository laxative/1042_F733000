#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define MAX 110
using namespace std;
bool adj[MAX][MAX];
int dfn[MAX], low[MAX];
int t=0,ans;
int s,n;
void dfs(int p, int i) {
	dfn[i] = low[i] = ++t;
	int child = 0;
	bool ap = false;
	for(int j=1;j<=n;++j) {
		if(adj[i][j] && j!=p) {
			if(dfn[j]) {
				low[i] = min(low[i],dfn[j]);
			} else {
				child++;
				dfs(i,j);
				low[i] = min(low[i],low[j]);
				if(low[j]>=dfn[i]) ap=true;
			}
		}
	}
	if ((child>1 || p!=-1) && ap) {
		ans++;
	}
	return;
}
void init() {
	t=0;
	ans=0;
	memset(adj,false,sizeof(adj));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
}
int main() {
	char line[MAX*4], *number;
	while (scanf("%d\n", &n) && n) {
		init();
		do {
			fgets(line, sizeof(line), stdin);
			s = 0;
			for (number = strtok(line," "); number != NULL; number = strtok(NULL," ")) {
				if (s) {
					t = atoi(number);
					adj[s][t] = true;
					adj[t][s] = true;
				} else {
					s = atoi(number);
				}
			}
		}while(s);
		dfs(-1,1);
		printf("%d\n", ans);
	}
	return 0;
}
