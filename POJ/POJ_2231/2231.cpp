#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
	long long position[10000];
	int cows;
	scanf("%d",&cows);
	long long sum(0);
	for(int i=0;i<cows;i++) {
		scanf("%lld",&position[i]);
	}
	sort(position,position+cows);
	for(int i=0;i<cows;i++) {
		for(int j=0;j<i;j++) {
			sum += position[i]-position[j];
		}
	}
	sum *= 2;
	printf("%lld\n",sum);
	return 0;
}
