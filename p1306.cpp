#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=1e8;
struct ma{int m[10][10];};
ma mul(ma a,ma b){
    ma c;
    memset(c.m,0,sizeof c.m);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
    return c;
}
ma a,b;
void qp(int k){
    while(k){
        if(k&1)b=mul(b,a);
        a=mul(a,a);
        k>>=1;
//		for(int i=1;i<=2;i++)
//			cout<<b.m[1][i]<<' ';
//		cout<<'\n';
    }
}
signed main(){
	int sto,orz,p,q,a1,a2,n;
	cin>>sto>>orz;
	n=__gcd(sto,orz);
	if(n==1){
		cout<<1;
		return 0;
	}
	a.m[1][1]=1,a.m[1][2]=1,a.m[2][1]=1;
	b.m[1][1]=1,b.m[1][2]=1;
	qp(n-2);
//	for(int i=1;i<=2;i++)
//		cout<<b.m[1][i]<<' ';
//	cout<<'\n';
	cout<<b.m[1][1]%mod;
}
