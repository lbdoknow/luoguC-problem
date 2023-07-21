#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+10;
bool ans[N];
int tot,r;
int a,b;
vector<int>G[N];
int dfn[N],low[N],cnt;
void dfs(int p){
	low[p]=++cnt;
	dfn[p]=cnt;
	int son=0;
	for(int i=0;i<G[p].size();i++){
		int t=G[p][i];
		if(!dfn[t]){
			son++;dfs(t);
			low[p]=min(low[p],low[t]);
			if(low[t]>=dfn[p]&&p!=r){
				if(dfn[i]<=dfn[b])
				ans[p]=1;
			}if(p==r&&son>=2){
				if(dfn[i]<=dfn[b]) 
				ans[p]=1;	
			}
		}
		else{
			low[p]=min(low[p],dfn[t]);
		}
	}
}
int main(){
	int n,f,t;
	cin>>n;
	while(cin>>f>>t && f+t!=0)
		G[f].pb(t),G[t].pb(f);
	cin>>a>>b;
	for(int i=1;i<=n;i++){
		if(ans[i]){
			return cout<<i<<' ',0;
		}
	}
	cout<<"No solution";
}
