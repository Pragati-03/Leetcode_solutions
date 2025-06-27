#include <iostream>
#include<vector>
#include<stack>

using namespace std;

int largestRectangleArea(vector<int>&height{
	int maxArea=0;
	stack<int>s;
	height.push_back(0);
	int n=height.size();
	
	for(int i=0;i<n;++i){
		while(!s.empty()&& height[i]<height[s.top()]){
			int heights=height[s.top()];
			s.pop();
			int width=s.empty()?i:i-s.top()-1;
			maxArea=max(maxArea,heights*width);
		}
		s.push(i);
	}
	return maxArea;
}
int main(){
	int n;
	cin>>n;
	vector<int>height(n);
	for(int i=0;i<n;++i){
		char ch;
		cin>>ch;
		height[i]=ch-'0';
	}
	cout<<largestRectangleArea(height)<<endl;
	return 0;
	
}
