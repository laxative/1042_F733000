#include<iostream>
#include<queue>
using namespace std;
int level,row,column;
char map[50][50][50];
int minute[50][50][50];
const int dir[6][3] = {{-1,0,0},{0,-1,0},{0,1,0},{1,0,0},{0,0,-1},{0,0,1}};		//dir = {z,y,x}
struct point {
	int x;
	int y;
	int z;
}start, cur, next;
void BFS(int z, int y, int x) {
	minute[z][y][x] = 0;
	queue<point> q;
	q.push(start);	//start
	map[z][y][x] = '#';		//visited

	while(!q.empty()) {		//have road to go
		cur = q.front();
		q.pop();
		
		for(int i=0;i<6;i++) {
			next.z = cur.z + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.x = cur.x + dir[i][2];

			if((next.x<0 || next.x>=column) || (next.y<0||next.y>=row) || (next.z<0||next.z>=level))	continue; //go out of the map
			
			if(map[next.z][next.y][next.x] != '#') { //road
				minute[next.z][next.y][next.x] = minute[cur.z][cur.y][cur.x] + 1;
				if(map[next.z][next.y][next.x] == 'E') {
					cout << "Escaped in "<< minute[next.z][next.y][next.x] << " minute(s)." << endl;
					return;
				}
				map[next.z][next.y][next.x] = '#';	//remember to set the road visited
				q.push(next);
			}
		}
	}
	cout << "Trapped!" << endl;
	return;	
}
int main() {
	while(cin >> level >> row >> column) {
		if((!level && !row) && !column)	break;
		int start_i, start_j, start_k;
		for(int i=0;i<level;i++) {
			for(int j=0;j<row;j++) {
				for(int k=0;k<column;k++) {
					cin >> map[i][j][k];
					if(map[i][j][k] == 'S')		{ start.z = i;	start.y = j;	start.x = k;}
				}
			}
		}
		BFS(start.z, start.y, start.x);
	}
	return 0;
}
