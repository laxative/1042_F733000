#include<iostream>
using namespace std;
int main() {
	int array[1000][1000],setnum[1000],loadnum[1000];
	int row,column;
	int nozero,count;
	while(cin >> row >> column) {
		for(int i=0;i<row;i++) {
			for(int j=0;j<column;j++) {
				array[i][j] = 0;
			}
		}
		for(int i=0;i<row;i++) {
			cin >> nozero;
			if(nozero == 0)		continue;
			for(int j=0;j<nozero;j++) {
				cin >> setnum[j];
			}
			for(int k=0;k<nozero;k++) {
				cin >> array[i][setnum[k]-1];
			}
		}
		cout << column << " " << row << endl;
		for(int i=0;i<column;i++) {
			count = 0;
			for(int j=0;j<row;j++) {
				if(array[j][i] != 0) { loadnum[count] = j+1;	count++;}
			}
			if(count == 0) {
				cout << 0 << endl << endl;
				continue;
			}
			cout << count;
			for(int j=0;j<count;j++) {
				cout << " " << loadnum[j];
			}
			cout << endl;
			for(int j=0;j<row;j++) {
				if(array[j][i] == 0)	continue;
				cout << array[j][i];
				if(count-1 != 0)	cout << " ";
				count--;
			}
			cout << endl;
		}
	}
	return 0;
}
