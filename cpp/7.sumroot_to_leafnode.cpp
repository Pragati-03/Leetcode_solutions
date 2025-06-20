#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};


int sumNumHelper(TreeNode* node,int currSum){
    if(!node){
    	return 0;
	}
	currSum=currSum*10+node->val;
		
	if(!node->left && !node->right){
		return currSum;
	}
		
	return sumNumHelper(node->left,currSum)+sumNumHelper(node->right,currSum);
	}
	
int sumNum(TreeNode* root){
	return sumNumHelper(root,0);
	}

int main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	int res=sumNum(root);
	cout<<res<<endl;
	
	return 0;
	
}
