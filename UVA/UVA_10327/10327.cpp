#include<iostream>
using namespace std;
int main() {
	int numbers;
	while(cin >> numbers) {
		int store[numbers], news[numbers];
		for(int i=0;i<numbers;i++) {
			cin >> store[i];
		}
		int times(0), temp;
		//bubble sort
		for(int i=numbers-1;i>0;i--) {
			for(int j=0;j<i;j++) {
					if(store[j] > store[j+1]) {
						temp = store[j]; store[j] = store[j+1]; store[j+1] = temp;
						times++;
					}
				}
			}
		cout << "Minimum exchange operations : " << times << endl;
	}
	return 0;
}
