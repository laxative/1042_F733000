#include<cstdio>
#include<cstring>
#define MAX 10100
using namespace std;
struct node{
	int l,r;
	bool isCovered;
	node *left, *right;
};
struct Post{
	int l,r;
};
Post poster[MAX];
node tree[MAX<<3];
int NodeCnt=0;
void build(node *rt, int l, int r) {
	rt->l = l;
	rt->r = r;
	rt->isCovered = false;
	if(l==r)   return;
	rt->left = tree + (++NodeCnt);
	rt->right = tree + (++NodeCnt);
	int m = (l+r) >> 1;
	build(rt->left,l,m);
	build(rt->right,m+1,r);
}
void query(node *rt, int l, int r) {
	if(rt->isCovered) return;
	if(rt->l==l && rt->r==r) {
		rt->isCovered = true;
		return;
	}
	int m =(rt->l + rt->r) >> 1;
	if(r<=m) {
		query(rt->left,l,r)
	}else if(m<l) {
		query(rt->right,l,r);
	}else {
		query(rt->left,l,m);
		query(rt->right,m+1,r);
	}
	if(rt->left->isCovered && rt->right->isCovered)
		rt->isCovered = true;
}
int main() {
	return 0;
}
