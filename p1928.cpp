#include<bits/stdc++.h>
using namespace std;
string solve(){
	int n;
	string s1="",s2;
	char c;
	while(cin>>c){
		if(c=='['){
			cin>>n;
			s2=solve();
			while(n--)s1+=s2;
		}
		else if(c==']')return s1;
		else s1+=c;
	}
}
int main(){
	cout<<solve();
} 
