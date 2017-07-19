#include<iostream>
using namespace std;
long long input[1000000], answer[1000000];
long long count;
//merge sort
//begin
void merge(long long *sort, long long low, long long high, long long mid) {
	long long int i=low, k=low, j=mid+1;
	while(i<=mid && j<=high) {
		if(sort[i] < sort[j])	answer[k++] = sort[i++];
		if(sort[i] > sort[j])	{answer[k++] = sort[j++];	count += mid-i+1;}
	}
	while(i <= mid)		answer[k++] = sort[i++];
	while(j <= high)	answer[k++] = sort[j++];
	for(int l=low;l<k;l++)	sort[l] = answer[l];
	return;
}
void mergesort(long long *sort, long long low, long long high) {
	long long int mid;
	if(low < high) {
		mid = (low + high)/2;
		mergesort(sort,low,mid);
		mergesort(sort,mid+1,high);
		merge(sort,low,high,mid);
	}
	return;
}
//end
int main() {
	long long num;		
	while(cin >> num) {
		if(num == 0)		break;
		for(int i=0;i<num;i++) {
			cin >> input[i];
		}
		count = 0;
		mergesort(input,0,num-1);
		cout << count << endl;
	}
	return 0;
}
