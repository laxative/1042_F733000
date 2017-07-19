#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	int n(0);
	map<string,bool> mapinput;
	mapinput.clear();
	string input[200000];
	while(cin >> input[n]) {
		mapinput[input[n]] = 1;
		n++;
	}
	string front,behind;
	//apart the word into two parts
	for(int i=0;i<n;i++) {
		for(int j=0;j<input[i].size()-1;j++) {
			front = input[i].substr(0,j+1);		//substr(begin,num)->catch from begin and catch num words
			if(!mapinput[front])	continue;
			behind = input[i].substr(j+1);		//catch from begin and catch all words behind
			if(!mapinput[behind])	continue;
			cout << input[i] << endl;
			break;
		}
	}
	return 0;
}
