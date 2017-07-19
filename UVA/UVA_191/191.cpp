#include<iostream>
#include<cmath>
#define eps 1e-10
using namespace std;

typedef struct point{
	double x,y;
	point(double x=0, double y=0):x(x),y(y){}
}point;
int dcmp(double x) {
	if(fabs(x)<eps) return 0;
	else return x<0?-1:1;
}
typedef point Vector;
Vector operator -(Vector a, Vector b) {
	return Vector(b.x-a.x,b.y-a.y);
}
double cross(Vector a, Vector b) {
	return a.x*b.y-a.y*b.x;
}
//check point c is between a and b or not
int in_interval(point a, point b, point c) {
	point min,max;
	if(a.x>b.x) min.x=b.x, max.x=a.x;
	else min.x=a.x, max.x=b.x;
	if(a.y>b.y) min.y=b.y, max.y=a.y;
	else min.y=a.y, max.y=b.y;

	if(min.x<=c.x && c.x<=max.x
			&& min.y<=c.y && c.y<=max.y) return 1;
	else return 0;
}
//check AB,CD has intersect or not
int intersect(point A, point B,
		point C, point D) {
	double d1=cross(A-C,D-C);
	double d2=cross(B-C,D-C);
	double d3=cross(C-A,B-A);
	double d4=cross(D-A,B-A);
	if(dcmp(d1*d2)<0 && dcmp(d3*d4)<0) return 1;
	if(dcmp(d1)==0 && in_interval(C,D,A)) return 1;
	if(dcmp(d2)==0 && in_interval(C,D,B)) return 1;
	if(dcmp(d3)==0 && in_interval(A,B,C)) return 1;
	if(dcmp(d4)==0 && in_interval(A,B,D)) return 1;
	return 0;


}
int main() {
	int cases;
	double s_x,s_y,e_x,e_y,lx,rx,by,ty;
	cin >> cases;
	while(cases--) {
		cin >> s_x >> s_y >> e_x >> e_y
			>> lx >> ty >> rx >> by;
		
		point s_line(s_x,s_y), e_line(e_x,e_y);
		point r1(lx,ty),r2(lx,by),r3(rx,ty),r4(rx,by);
		bool flag=false;
		if(intersect(s_line,e_line,r1,r2)) flag=true;
		if(intersect(s_line,e_line,r1,r3)) flag=true;
		if(intersect(s_line,e_line,r2,r4)) flag=true;
		if(intersect(s_line,e_line,r3,r4)) flag=true;
		if(flag) cout << "T" << endl;
		else cout << "F" << endl;
	}
	return 0;
}
