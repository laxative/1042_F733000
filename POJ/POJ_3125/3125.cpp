#include<iostream>
using namespace std;
int main() {
	int Case;	cin >> Case;
	int i, num, my_pos, front, back, time;
	int arr[100000];
	while(Case--) {
		cin >> num >> my_pos;
		back = 0,	time = 0;
		for(i=0;i<num;i++) {
			cin >> arr[i];
			back++;
		}
		front = 0;
		while(front < back) {
			for(i=front;i<back;i++) {
				if(arr[i] > arr[front]) {
					arr[back++] = arr[front];
					break;
				}
			}
			if(i>=back) {
				time++;
				if(front == my_pos) {
					cout << time << endl;
					break;
				}else		front++;
			}else if(front == my_pos) {
				my_pos = back-1;
			}else {
				front++;
			}
		}
	}
	return 0;
}
