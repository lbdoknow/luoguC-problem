#include<stack>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
stack<int>a,b;
string ans;
int p[1310],tmp[1310];
int main(){
	int n,tot=0;
	cin>>n;
	for(int i=1;i<=n;p[i]=1,i++)cin>>tmp[i];
	for(int i=n;i>=1;i--)a.push(tmp[i]);
	for(int i=n;i>=1;i--){
		if(p[i]==1){
			while(a.top()!=i){
				tot++;
				ans+="A B\n";
				b.push(a.top());
				a.pop();
				p[b.top()]=2;
			}
			tot++;
			ans+="A C\n";
			a.pop();
		}
		if(p[i]==2){
			while(b.top()!=i){
				tot++;
				ans+="B A\n";
				a.push(b.top());
				b.pop();
				p[a.top()]=1;
			}
			tot++;
			ans+="B C\n";
			b.pop();
		}
	}
	cout<<tot<<'\n';
	cout<<ans;
} 
