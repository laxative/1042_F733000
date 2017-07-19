#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 105
using namespace std;
int num,test;
string city[MAXN];
bool adj[MAXN][MAXN];
int dfn[MAXN],low[MAXN];
int t;
vector<string> ans;
void init() {
	memset(adj,false,sizeof(adj));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	t = 0;
	ans.clear();
}
void dfs(int p,int i) {
	dfn[i] = low[i] = ++t;
	int child = 0;
	bool ap = false;
	for(int j=1;j<=num;++j) {
		if(adj[i][j] && j!= p) {
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
	if((child>1 || p!=-1) && ap) {
		ans.push_back(city[i]);
	}
	return;
}
int main() {
	int cases=1;
	while(cin >> num) {
		if(!num) break;
		init();
		for(int i=1;i<=num;++i) {
			cin >> city[i];
		}
		cin >> test;
		string str, str2;
		int a,b;
		while(test--) {
			cin >> str >> str2;
			for(int i=1;i<=num;++i) {
				if(str==city[i]) {
					a = i;
				}else if(str2==city[i]){
					b = i;
				}
			}
			adj[a][b] = true;
			adj[b][a] = true;
		}
		for(int i=1;i<=num;++i)		dfs(-1,i);
		sort(ans.begin(),ans.end());
		if (cases != 1) cout << endl;
		cout << "City map #" << cases++ << ": "<< ans.size() << " camera(s) found" << endl;
		for (vector<string>::iterator iter = ans.begin(); iter != ans.end(); ++iter)
			cout << *iter << endl;
	}
	return 0;
}
