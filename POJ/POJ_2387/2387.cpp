#include<iostream>
#define INF 99999999
using namespace std;
struct node{
	int placeA;
	int placeB;
	int dis;
}point[10000];
int dis[10000];
void Relax(node a) {
	if(dis[a.placeA]+a.dis<dis[a.placeB]) {
		dis[a.placeB] = dis[a.placeA] + a.dis;
	}
	if(dis[a.placeB]+a.dis<dis[a.placeA]) {
		dis[a.placeA] = dis[a.placeB] + a.dis;
	}
	return;
}
void BellmanFord(int road, int places, node *a) {
	dis[places] = 0;
	for(int i=1;i<places;++i) {
		dis[i] = INF;
	}
	for(int times=0;times<places-1;++times) {
		for(int i=0;i<road;++i) {
			Relax(a[i]);
		}
	}
	return;
}
int main() {
	int road, places;
	cin >> road >> places;
	for(int i=0;i<road;++i) {
		cin >> point[i].placeA >> point[i].placeB >> point[i].dis;
	}
	BellmanFord(road,places,point);
	cout << dis[1] << endl;
	return 0;
}
