#include<bits/stdc++.h>
using namespace std;
struct lsqxx{
    int t,nxt;
}e[1000000];
int num[200000],cnt,tot;
void addedge(int f,int t){
    e[++cnt].nxt=num[f];
    e[cnt].t=t,num[f]=cnt;
}
stack<int>st;
int cot,bl[200000],a[200000];
int dfn[200000],low[200000],in[200000];
void dfs(int p){
    st.push(p);
    in[p]=1;
    dfn[p]=low[p]=++tot;
    for(int i=num[p];i;i=e[i].nxt){
        int t=e[i].t;
        if(!dfn[t]){
            dfs(t);
            low[p]=min(low[p],low[t]); 
        }
        else if(in[t])
            low[p]=min(low[p],dfn[t]);
    }
    if(dfn[p]==low[p]){
        cot++;
        int q;
        do{
            q=st.top();
            in[q]=0;
            st.pop();
            bl[q]=cot;
            a[cot]++;
        }while(p!=q);
    }
}
int goin[200000];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    	int f,t;
    	cin>>f>>t;
    	addedge(f,t);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])dfs(i);
    for(int i=1;i<=n;i++)
        for(int j=num[i];j;j=e[j].nxt){
            int t=e[j].t;
            if(bl[i]!=bl[t])goin[bl[t]]++;
        }
    int cont=0;
    for(int i=1;i<=cot;i++)
        if(goin[i]==0)cont++;
    cout<<cont;
}
