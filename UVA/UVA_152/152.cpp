#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXN 5001
using namespace std;
int d[10]={0};
struct Point{
	double x,y,z;
	Point(double x=0, double y=0, double z=0):x(x),y(y),z(z) {}
}point[MAXN];

int caldis(struct Point a,struct Point b) {
	double dis;
	dis=sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2)+pow(b.z-a.z,2));
	return int(dis);
}
int main() {
	int x,y,z,num=0;
	while(cin >> x >> y >> z) {
		if(!x && !y && !z) break;
		point[num].x=x;
		point[num].y=y;
		point[num].z=z;
		num++;
	}
	for(int i=0;i<num;++i) {
		int min=100;
		for(int j=0;j<num;++j) {
			if(i==j) continue;
			if(caldis(point[i],point[j])<min) min=caldis(point[i],point[j]);
		}
		if(min<10) d[min]++;
	}
	for(int i=0;i<10;++i) printf("%4d",d[i]);
	cout << endl;
	return 0;
}
