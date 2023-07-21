#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=19930726;
char a[2500000],b[2500000];
int p[2500000],cnt[2500000];
void init(){
	int l=strlen(a),tot=2;
	b[0]='%',b[1]='|';
	for(int i=0;i<l;i++){
		b[tot++]=a[i];
		b[tot++]='|';
	}b[tot]='&';
}
int qp(int a,int k){
	int ans=1;
	while(k){
		if(k&1)ans=a*ans%mod;
		a=a*a%mod;
		k>>=1;
	}
	return ans;
}
void manacher(){
	int l=strlen(b),c,f=0;
	for(int i=1;i<l;i++){
		if(i<f)p[i]=min(p[2*c-i],f-i);
		else p[i]=1;
		while(b[i+p[i]]==b[i-p[i]])p[i]++;
		if(i+p[i]>f)c=i,f=i+p[i];
		if((p[i]-1)%2)cnt[p[i]-1]++;
	}
}
signed main(){
	int n,k,sum=0,ans=1;
	cin>>n>>k>>a;
	init();
	manacher();
	for(int i=n&1?n:(n+1);i>=1;i-=2){
		sum+=cnt[i];
		if(k>sum){
			ans=(ans*qp(i,sum)%mod);
			k-=sum;
		}
		else{
			ans=(ans*qp(i,k)%mod);
			k=0;
		}
	} 
	cout<<ans;
} 
