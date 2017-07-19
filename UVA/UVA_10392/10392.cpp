#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;
vector<long long int> prime;
bool isPrime(int n) {
	for(int i=2; i*i<n; i++) {
		if(n % i == 0)	return false;
	}
	return true;
}
void MakePrime() {
	prime.push_back(2);
	prime.push_back(3);
	for(int i=5, gap=2; i<=MAX; i+=gap, gap=6-gap) {
		if(isPrime(i))		prime.push_back(i);
	}
	return;
}

int main() {
	long long int input;
	MakePrime();
	while(1) {
		cin >> input;
		if(input < 0)	break;
		for(int i=0;i<prime.size();i++) {
			if(prime[i]*prime[i] > input)	break;
			if(input % prime[i] == 0) {
				input /= prime[i];
				cout << "    " << prime[i] << endl;
				i--;
			}
		}
		if(input != 1)	cout << "    " << input << endl;
		cout << endl;
	}
	return 0;
}
