#include<iostream>
using namespace std;

int main() {
	int count;
	cin >> count;
	int arr[count][2];
	for(int i=0;i<count;i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	int answer;
	for(int i=0;i<count;i++) {
		cout << "Scenario #" << i+1 << ":" << endl;
		answer = arr[i][0] * arr[i][1];
		if(answer % 2 == 0) {
			cout << answer << ".00" << endl << endl;
		}else{
			cout << answer << ".41" << endl << endl;
		}
	}
	return 0;
}
