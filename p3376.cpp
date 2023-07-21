#include<bits/stdc++.h>
using namespace std;
#define int long long
#define min(a,b)    [](int _a,int _b){return _a<_b?_a:_b;}(a,b)
int n,m,s,t;
struct Edge{
    int v,w,nxt;
    Edge(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
    Edge(){}
}e[114514];
int head[114514],cnt=1;
int depth[1919810],cur[114514];
void add(int u,int v,int w){
    e[++cnt]=Edge(v,w,head[u]);
    head[u]=cnt;
    e[++cnt]=Edge(u,0,head[v]);
    head[v]=cnt;
}
int bfs(){
    for(int i=1;i<=n;i++)   depth[i]=-1;
    depth[s]=0;
    cur[s]=head[s];
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=head[now];i;i=e[i].nxt){
            int v=e[i].v;
            if(e[i].w>0&&depth[v]==-1){
                depth[v]=depth[now]+1;
                q.push(v);
                cur[v]=head[v];
            }
        }
    }
    return depth[t]!=-1;
}
int dfs(int now=s,int flow=LLONG_MAX){
    if(now==t)  return flow;
    int tmp=flow;
    for(int i=head[now];i&&tmp;i=e[i].nxt){
        int v=e[i].v;
        int w=e[i].w;
        cur[now]=v;
        if(w>0&&depth[v]==depth[now]+1){
            int out=dfs(v,min(flow,w));
            if(!out)    depth[v]=-1;
            flow-=out;
            e[i].w-=out;
            e[i^1].w+=out;
        }
    }
    return tmp-flow;
}
int ans=0;
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    while(bfs()){
        ans+=dfs();
    }
    cout<<ans<<endl;
    return 0;
}
