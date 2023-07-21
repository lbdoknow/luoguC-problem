#include<bits/stdc++.h>
const int maxn=5e7;
using namespace std;
int a[maxn],root[maxn];
struct node{
	int l_son,r_son,value;
}t[maxn];
int nop=0;
inline int new_point(int cpy){
	t[++nop]=t[cpy];
	return nop;
}
inline int build(int l,int r){
	int now=++nop;
	if(l==r){
		t[now].value=a[l];
		return now;
	}
	int mid=(l+r)/2;
	t[now].l_son=build(l,mid);
	t[now].r_son=build(mid+1,r);
	return now;
}
inline int update(int p,int l,int r,int x,int v){
	p=new_point(p);
	if(l==r)t[p].value=v;
	else{
		int mid=(l+r)/2;
		if(x<=mid)t[p].l_son=update(t[p].l_son,l,mid,x,v);
		else t[p].r_son=update(t[p].r_son,mid+1,r,x,v);
	}
	return p;
}
inline int query(int p,int l,int r,int x){
	if(l==r)return t[p].value;
	else{
		int mid=(l+r)/2;
		if(x<=mid)return query(t[p].l_son,l,mid,x);
		else return query(t[p].r_son,mid+1,r,x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	root[0]=build(1,n);
	for(int i=1;i<=m;i++){
		int rt,md,x,y;
		cin>>rt>>md>>x;
		if(md==1){
			cin>>y;
			root[i]=update(root[rt],1,n,x,y);
		}else{
			cout<<query(root[rt],1,n,x)<<'\n';
			root[i]=root[rt];
		}
	}
}
