#include <iostream>
#include<string>
using namespace std;

bool isPalindrome(const string &s, int start,int end){
	if(s[start]!=s[end]){
		return false;
	start++;
	end--;
	}
	return true;
}

string Largestpalindrome(const string &str){
	int maxLen=0;
	string res="";
	int n=str.length();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(isPalindrome(str,i,j) && (j-i+1)>maxLen){
				maxLen=j-i+1;
				res=str.substr(i,maxLen);
			}
		}
	}
	return res;
}
int main(){
	string s;
	cin>>s;
	string res=Largestpalindrome(s);
	cout<<res<<endl;
	
	return 0;
	
}
