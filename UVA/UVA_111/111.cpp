#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int LCS[100][100] = {0};
int correct_order[100], event_order[100];
int main() {
	while(scanf("%d",&n)!=EOF) {
		for(int i=1;i<=n;++i)  scanf("%d",&correct_order[i]);
		int correct[100] = {0};
		for(int i=1;i<=n;++i)  correct[correct_order[i]] = i;
		while(scanf("%d",&event_order[1])!=EOF) {
			for(int i=2;i<=n;++i)  scanf("%d",&event_order[i]);
			int event[100] = {0};
			for(int i=1;i<=n;++i)  event[event_order[i]] = i;
			//set LCS board
			memset(LCS,0,10000*sizeof(int));
			for(int i=1;i<=n;++i) {
				for(int j=1;j<=n;++j) {
					if(event[i]==correct[j])  LCS[i][j] = LCS[i-1][j-1] +1;
					else LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
				}
			}
			printf("%d\n",LCS[n][n]);
		}
	}
	return 0;
}
