#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 50000
using namespace std;
struct node{
	int min, max;
	int l,r;  //limit(from 1 to n)
	node *left, *right;
};
node tree[MAX << 5];
int num[MAX+1];
int Nodenum=0, ansmin, ansmax;
void build(node *rt, int l, int r) {
	rt->l = l;
	rt->r = r;
	if(l==r) {
		rt->min = rt->max = num[l];
		return;
	}
	rt->left = tree + (++Nodenum);
	rt->right = tree + (++Nodenum);
	int m = (l+r) >> 1;
	build(rt->left,l,m);
	build(rt->right,m+1,r);
	rt->max = max(rt->left->max, rt->right->max);
	rt->min = min(rt->left->min, rt->right->min);
}
void query(node *rt, int l, int r) {
	if(rt->l == l && rt->r ==r) {
		ansmax = max(ansmax,rt->max);
		ansmin = min(ansmin,rt->min);
		return;
	}
	int m = (rt->l + rt->r) >> 1;
	if(r <= m) {
		query(rt->left,l,r);
	}else if(l > m) {
		query(rt->right,l,r);
	}else {
		query(rt->left,l,m);
		query(rt->right,m+1,r);
	}
}
int main() {
	int numbers, find, l, r;
	while(scanf("%d %d",&numbers,&find) != EOF) {
		memset(tree,0,(sizeof(tree)));
		for(int i=1;i<=numbers;i++)  scanf("%d",&num[i]);
		build(tree,1,numbers);
		for(int i=0;i<find;i++) {
			scanf("%d %d",&l,&r);
			ansmax=0, ansmin=10000000;
			query(tree,l,r);
			printf("%d\n",ansmax-ansmin);
		}
	}
	return 0;
}
