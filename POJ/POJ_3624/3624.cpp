#include<iostream> 
#include<algorithm>
#include<cstring>
using namespace std;
int value[100000], v[100000], w[100000];
void knapsack(int n, int W) {
	memset(value,0,sizeof(value));
	for(int i=0;i<n;i++) {
		for(int m=W;m-w[i]>=0;m--) {
			value[m] = max(value[m],value[m-w[i]] + v[i]);
		}
	}
	return;
}
int main() {
	int Case, max_weight;
	cin >> Case >> max_weight;
	for(int i=0;i<Case;i++)  cin >> w[i] >> v[i];
	knapsack(Case,max_weight);
	cout << value[max_weight] << endl;
	return 0;
}
