#include<iostream>
using namespace std;
void trans(int **store, int number);
int main() {
	int number;
	while(cin >> number) {
		int store[number][3];
		for(int i=0;i<number;i++) {
			for(int j=0;j<3;j++) {
				cin >> store[i][j];
			}
		}
		trans(store,number);
		for(int i=0;i<number;i++) {
			cout << "Case " << i+1 << ": " << store[i][1] << endl;
		}
	}
	return 0;
}
void trans(int **store, int number) {
	int temp;
	for(int i=0;i<number;i++) {
		for(int j=2;j>=0;j--) {
			for(int k=0;k<j;k++) {
				if(store[i][k] > store[i][j]) {
					temp = store[i][k]; store[i][k] = store[i][j]; store[i][j] = temp;
				}
			}
		}
	}
}
