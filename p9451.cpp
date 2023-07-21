#include<bits/stdc++.h>
#define int long long
using namespace std;
int lb(int num){
	return num&-num;
}
int popcount(long long num){
	int cnt=0;
	while(num)
		num-=lb(num),cnt++;
	return cnt;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int k=popcount(n);
		if(k>=3)cout<<"No,Commander\n";
		else if(k==2)cout<<n+lb(n)<<endl;
		else cout<<n+1<<endl;
	}
} 
