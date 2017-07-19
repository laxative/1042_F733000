#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct Point{
	double x,y;
	Point(double x=0, double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator -(Vector a,Vector b) {
	return Vector(a.x-b.x, a.y-b.y);
}
double cross(Vector a, Vector b) {
	return a.x*b.y-a.y*b.x;
}
Point oper(char c, Point in) {
	Point out;
	switch(c) {
		case '1':
			out.x = in.x-1, out.y = in.y-1;
			break;
		case '2':
			out.x = in.x, out.y = in.y-1;
			break;
		case '3':
			out.x = in.x+1, out.y = in.y-1;
			break;
		case '4':
			out.x = in.x-1, out.y = in.y;
			break;
		case '5':
			out.x = in.x, out.y = in.y;
			break;
		case '6':
			out.x = in.x+1, out.y = in.y;
			break;
		case '7':
			out.x = in.x-1, out.y = in.y+1;
			break;
		case '8':
			out.x = in.x, out.y = in.y+1;
			break;
		case '9':
			out.x = in.x+1, out.y = in.y+1;
			break;
	}
	return out;
}
int main() {
	int cases;
	string input;
	cin >> cases;
	Point init,cur,before;
	while(cases--) {
		long long int area=0;
		cin >> input;
		cur = oper(input[0],cur);
		for(int i=1;i<input.length();++i) {
			before = cur;
			cur = oper(input[i],cur);
			area += static_cast<long long int>(cross(cur-init,before-init));
		}
		if(area<0) area = -area;
		if(area%2==0)	cout << area/2 << endl;
		else cout << (area-1)/2 << ".5" << endl;
	}
	return 0;
}
