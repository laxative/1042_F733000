#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long numbers[10000];
	int i(0);
	long long even;
	while(cin >> numbers[i]) {
		sort(numbers,numbers+i+1);
		if(i==0) { 
			cout << numbers[i] << endl;
		}else if(i%2 != 0) {
			even = (numbers[i/2] + numbers[(i/2)+1])/2;
			cout << even << endl;
		}else {
			cout << numbers[i/2] << endl;
		}
		i++;
	}
	return 0;
}
