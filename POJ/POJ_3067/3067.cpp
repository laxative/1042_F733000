//one for descending, and one for incending

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct city{
	long long int w;
	long long int e;
}a[1000000], sorted[1000000];
long long int cross;
//e -> from high to low
void merge(int low, int high, int mid) {
	int i,j,k;
	i=low, j=mid+1; k=0;
	while(i<=mid && j<=high) {
		if(a[i].e > a[j].e)		{cross+= high-j+1;	sorted[k++] = a[i++];}
		else		sorted[k++] = a[j++];
	}
	while(i<=mid)		sorted[k++] = a[i++];
	while(j<=high)		sorted[k++] = a[j++];

	k=0;
	for(int l=low;l<=high;l++)		a[l] = sorted[k++];
	return;
}
void mergesort(int low, int high) {
	int mid;
	if(low < high) {
		mid = (low + high) / 2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,high,mid);
	}
	return;
}
//w -> from low to high
bool cmp(city a, city b) {
	if(a.w == b.w)	return a.e < b.e;
	else	return a.w < b.w;
}
int main() {
	long long int Case;	scanf("%lld",&Case);
	long long int left,right,road;
	for(int n=1;n<=Case;n++) {
		scanf("%lld %lld %lld",&left,&right,&road);
		for(int i=0;i<road;i++) {
			scanf("%lld %lld",&a[i].w,&a[i].e);
		}
		cross = 0;
		sort(a,a+road,cmp);
		mergesort(0,road-1);
		printf("Test case %d: %lld\n",n,cross);
	}
	return 0;
}
