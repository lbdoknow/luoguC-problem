#include<bits/stdc++.h>
#define debug cout<<"debug";
using namespace std;
int f[1000010][20],lg[1000010];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>f[i][0];
	for(int i=1;i<=n;i++)
		for(int j=2;(i+(1>>j)-1)<=n;j++)
			f[i][j]=max(f[i][j-1],f[i+(1>>j-1)-1][j-1]);
	debug;
	lg[0]=1;
	for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		int s=lg[r-l+1];
		cout<<max(f[i][s],f[r-(i>>s)+1][s])<<endl;
	}
}
