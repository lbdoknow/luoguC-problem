#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],p[N],s[N];
bool b[N];
int n,len,tot,m;
int h(int p){return (p-1)*len+1;}
int t(int p){return min(p*len,n);}
void ch(int k){
	s[p[k]]-=a[k],a[k]=sqrt(a[k]),s[p[k]]+=a[k];
}
void cb(int k){
	for(int i=h(k);i<=t(k);i++)
		if(a[i]>=2)return;
	b[k]=1;
}
void update(int l,int r){
	if(p[l]==p[r]&&!b[p[l]]){
		for(int i=l;i<=r;i++)
			ch(i);
		cb(p[l]);
		return;
	}
	if(!b[p[l]]){
		for(int i=l;i<=t(p[l]);i++)
			ch(i);
		cb(p[l]); 
	}
	for(int i=p[l]+1;i<p[r];i++){
		if(!b[i]){
			for(int j=h(i);j<=t(i);j++)
				ch(j);
			cb(i);
		}
	}
	if(!b[p[r]]){
		for(int i=h(p[r]);i<=r;i++)
			ch(i);
		cb(p[r]);
	}
}
int query(int l,int r){
	int ans=0;
	if(p[l]==p[r]){
		for(int i=l;i<=r;i++)
			ans+=a[i];
		return ans;
	}
	for(int i=l;i<=t(p[l]);i++)
		ans+=a[i];
	for(int i=p[l]+1;i<p[r];i++)
		ans+=s[i];
	for(int i=h(p[r]);i<=r;i++)
		ans+=a[i];
	return ans;
}
void mian()
{
	memset(s,0,sizeof s);
	memset(b,0,sizeof b);
	len=sqrt(n);
	tot=ceil(sqrt(n));
	for(int i=1;i<=n;i++)
		p[i]=(i-1)/len+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[p[i]]+=a[i];
	}cin>>m;
	for(int i=1;i<=m;i++){
		int md,l,r,c;
		cin>>md>>l>>r;
		if(l>r)swap(l,r);
		if(md==0)update(l,r);
		else cout<<query(l,r)<<'\n';
	}
    return;
}
signed main(){
	int tot=1;
	while(~scanf("%d",&n)){
		cout<<"Case #"<<tot++<<":\n"; 
		mian();
		cout<<'\n';
	}
}
