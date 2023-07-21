#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct lsqxx{
	int t,v,nxt;
}g[N];
int s[N],cnt=0,n,m;
void addedge(int f,int t,int v){
	g[++cnt].nxt=s[f];
	g[cnt].t=t;
	g[cnt].v=v;
	s[f]=cnt;
}
int nsp(){ 
	for(int i=1;i<=n;i++)
		addedge(n+1,i,0);
	return n+1;
}
int dis[N];
void debug(){
	for(int i=1;i<=n+1;i++)cout<<dis[i]<<' ';
	cout<<'\n';
}
bool bellman_ford(int p){
	memset(dis,0,sizeof dis);
	dis[p]=0;
	for(int i=1;i<=n;i++)
		for(int f=1;f<=n+1;f++)
			for(int j=s[f];j;j=g[j].nxt){
				int t=g[j].t;
				if(dis[t]<dis[f]+g[j].v){
					dis[t]=dis[f]+g[j].v;
				}
			}
	for(int f=1;f<=n+1;f++)
		for(int j=s[f];j;j=g[j].nxt){
			int t=g[j].t;
			if(dis[t]<dis[f]+g[j].v){
				return 1;
			}
		}
	return 0;		
	 
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int f,t,v;
		cin>>f>>t>>v;
		addedge(f,t,-v);
	}
	if(bellman_ford(nsp()))cout<<"NO SOLUTION\n";
	else
		for(int i=1;i<=n;i++)
			cout<<dis[i]<<'\n';
	 
} 
