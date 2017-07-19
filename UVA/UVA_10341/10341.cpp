#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double p,q,r,s,t,u;
double function(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
void search(double a, double b) {
	for(int i=0;i<100;i++) {
		double mid = (a + b) / 2;
		double value = function(mid);
		if(abs(value) < 1e-8) {
			printf("%.4lf\n",mid);
			return;
		}
		else if(value < 0)	b = mid;
		else	a = mid;
	}
	printf("No solution\n");
	return;
}
int main() {
	while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u) != EOF) {
		search(0.0000,1.0000);
	}
	return 0;
}
