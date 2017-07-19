#include<iostream>
#include<cmath>
#define MAXN 1005
#define eps 1e-10
using namespace std;
const double PI = acos(-1.0);
struct Point{
	double x,y;
	Point(){}
	Point(double x, double y):x(x),y(y){}
}point[MAXN];
typedef Point Vector;

Vector operator -(Vector a,Vector b) {
	return Vector(a.x-b.x, a.y-b.y);
}
int dcmp(double x) {
	if(fabs(x)<eps) return 0;
	else return x<0?-1:1;
}
double cross(Vector a, Vector b) {
	return a.x*b.y-a.y*b.x;
}

double calarea(int num) {
	double area=0;
	for(int i=1;i<num-1;++i) {
		area += cross(point[i]-point[0],point[i+1]-point[0]);
	}
	return fabs(area/2);
}
int main() {
	int num,pointnum;
	double t,v,R,T;
	while(cin >> num) {
		v=0;
		if(!num) break;
		for(int i=0;i<num;++i) {
			cin >> t;
			pointnum=0;
			cin >> point[0].x >> point[0].y;
			while(++pointnum) {
				cin >> point[pointnum].x >> point[pointnum].y;
				if(dcmp(point[pointnum].x-point[0].x)==0 
						&& dcmp(point[pointnum].y-point[0].y)==0) break;
			}
			v += t * calarea(pointnum);
		}
		cin >> R >> T;
		double cir = R*R*PI*T;
		cout << int(v/cir) << endl;
	}
	return 0;
}
