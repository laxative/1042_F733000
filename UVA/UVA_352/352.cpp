#include<iostream>
using namespace std;
char map[30][30];
void DFS(int x, int y, int max);
int main() {
	int times(1), pixel;
	while(cin >> pixel) {
		//set map
		for(int i=0;i<pixel;i++) {
			for(int j=0;j<pixel;j++) {
				cin >> map[i][j];
			}
		}
		int num(0);
		for(int i=0;i<pixel;i++) {
			for(int j=0;j<pixel;j++) {
				if(map[i][j] == '1') {
					DFS(i,j,pixel-1);
					num++;
				}
			}
		}
		cout << "Image number " << times << " contains " << num << " war eagles." << endl;
		times++;
	}
	return 0;
}
void DFS(int x, int y, int max) {
	map[x][y] = '0';
	//left top
	if((map[x-1][y-1] == '1' && x>0) && y>0) DFS(x-1,y-1,max);
	//top
	if(map[x][y-1] == '1' && y>0) DFS(x,y-1,max);
	//right top
	if((map[x+1][y-1] == '1' && y>0) && x<max) DFS(x+1,y-1,max);
	//left
	if(map[x-1][y] == '1' && x>0)	DFS(x-1,y,max);
	//right
	if(map[x+1][y] == '1' && x<max) DFS(x+1,y,max);
	//left down
	if((map[x-1][y+1] == '1' && x>0) && y<max) DFS(x-1,y+1,max);
	//down
	if(map[x][y+1] == '1' && y<max) DFS(x,y+1,max);
	//right down
	if((map[x+1][y+1] == '1' && x<max) && y<max) DFS(x+1,y+1,max);
	return;
}
