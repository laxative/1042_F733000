#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 100000
using namespace std;
struct node{
	int l,r;
	long long int sum,inc;
	node *left, *right;
};
node tree[MAX << 5];
long long int num[MAX+1];
long long int Nodenum=0, ans_sum;
void build(node *rt, int l, int r) {
	rt -> l = l;
	rt -> r = r;
	if(l==r) {
		rt -> sum = num[l];
		rt -> inc = 0;
		return;
	}
	rt -> left = tree + (++Nodenum);
	rt -> right = tree + (++Nodenum);
	int m = (l+r) >> 1;
	build(rt->left,l,m);
	build(rt->right,m+1,r);
	rt->sum = rt->left->sum + rt->right->sum;
}
void pushdown(node *rt) {
	if(rt->inc) {
		rt->left->inc += rt->inc;
		rt->right->inc += rt->inc;
		rt->left->sum += (((rt->left->r - rt->left->l)+1) * rt->inc);
		rt->right->sum += (((rt->right->r - rt->right->l)+1) * rt->inc);
		rt->inc = 0;
	}
}
void query(node *rt, int l, int r) {
	if(rt->l == l && rt->r == r) {
		ans_sum += rt->sum;
		return;
	}
	pushdown(rt);
	int m = (rt->l + rt->r) >> 1;
	if(r<=m) {
		query(rt->left,l,r);
	}else if(m<l) {
		query(rt->right,l,r);
	}else {
		query(rt->left,l,m);
		query(rt->right,m+1,r);
	}
}
void update(node *rt, int l, int r, long long int v) {
	if(rt->l == l && rt->r == r) {
		rt->inc += v;
		rt->sum += (((rt->r - rt->l)+1)*v);
		return;
	}
	pushdown(rt);
	int m = (rt->l + rt->r) >> 1;
	if(r<=m) {
		update(rt->left,l,r,v);
	}else if(m < l){
		update(rt->right,l,r,v);
	}else {
		update(rt->left,l,m,v);
		update(rt->right,m+1,r,v);
	}
	rt->sum = rt->left->sum + rt->right->sum;
}
int main() {
	long long int numbers,oper,l,r,v;
	char ch;
	scanf("%lld %lld",&numbers,&oper);
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=numbers;i++)  scanf("%lld",&num[i]);
	build(tree,1,numbers);
	while(oper) {
		ans_sum = 0;
		scanf("%c",&ch);
		if(ch == 'Q') {
			scanf("%lld %lld",&l,&r);
			query(tree,l,r);
			printf("%lld\n",ans_sum);
			oper--;
		}else if(ch == 'C') {
			scanf("%lld %lld %lld",&l,&r,&v);
			update(tree,l,r,v);
			oper--;
		}
	}
	return 0;
}
