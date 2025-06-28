#include <iostream>
#include<vector>
#include<string>

using namespace std;

bool isMatch(const string &pattern,const string &str){
	int m=pattern.length();
	int n=str.length();
	
	vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
	dp[0][0]=true;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;j++){
			if(pattern[i-1]==str[j-1] || pattern[i-1]=='?'){
				dp[i][j]=dp[i-1][j-1];
			}else if(pattern[i-1]=='*'){
				dp[i][j]=dp[i-1][j] || dp[i][j-1];
			}
		}
	}
	return dp[n][m];
}

int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	cout<<"String 2:"<<s2;
	if(isMatch(s1,s2)){
		cout<<"Strings match"<<endl;
	}else{
		cout<<"Strings doesnt match"<<endl;
	}
	return 0;
}
