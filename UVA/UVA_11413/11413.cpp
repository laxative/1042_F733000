#include<iostream>
using namespace std;
int main() {
	int a,b;
	int sort[1000000];
	while(cin >> a >> b) {
		int left=0, right=0, mid;  //left->the largest amount, right->sum of amount
		for(int i=0;i<a;i++) {
			cin >> sort[i];
			if(sort[i] > left) left = sort[i];
			right += sort[i];
		}
		while(left<right) {  //binary search(from left to right)
			mid = (left+right)/2;
			int sum=0;
			int bottle=0;
			for(int i=0;i<a;i++) {
				sum += sort[i];
				if(sum>mid) {
					bottle++;
					sum = sort[i];
				}
				else if(sum == mid) {
					bottle++;
					sum = 0;
				}
			}
			if(sum>0) bottle++;
			if(bottle>b) left = mid+1;
			else right = mid;
		}
		cout << left << endl;
	}
	return 0;
}
