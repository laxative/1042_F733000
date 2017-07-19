#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	int Case;
	scanf("%d",&Case);
	while(Case--) {
		char *str1 = new char[10010];
		char *str2 = new char[1000100];
		scanf("%s",str1); 
		scanf("%s",str2); 
		//set fail function
		int *pi = new int[strlen(str2)];
		pi[0] = -1;
		for(int i=1, cur_pos=-1;i<strlen(str1);++i) {
			while(cur_pos>=0 && str1[i]!=str1[cur_pos+1])
				cur_pos = pi[cur_pos];
			if(str1[i]==str1[cur_pos+1]) ++cur_pos;
			pi[i]=cur_pos;
		}
		//KMP
		int result = 0;
		for(int i=0, cur_pos=-1; i<strlen(str2); ++i) {
			while(cur_pos>=0 && str2[i]!=str1[cur_pos+1])
				cur_pos=pi[cur_pos];
			if(str2[i]==str1[cur_pos+1]) ++cur_pos;
			if(cur_pos+1==strlen(str1)) {
				cur_pos=pi[cur_pos];
				++result;
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
