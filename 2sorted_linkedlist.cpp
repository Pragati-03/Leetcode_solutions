#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//creating a linkedlist
class Node{
	public:
		int val;
		Node* next;
		Node(int x){
			val=x;
			next=nullptr;
		}
};
//sorting 2 lists
Node* sortedNodes(Node* head1, Node* head2){
	vector<int>arr;
	while(head1!=nullptr){
		arr.push_back(head1->val);
		head1=head1->next;
	}
	while(head2!=nullptr){
		arr.push_back(head2->val);
		head2=head2->next;
	}
	sort(arr.begin(),arr.end()); //sorting the array
	//creating an extra space to store the array in form of linkedlist
	Node* dummy=new Node(-1);
	Node* curr=dummy;
	for(int i=0;i<arr.size();i++){
		curr->next=new Node(arr[i]);
		curr=curr->next;
	}
	return dummy->next;
}

//printing the sorted list obtained
void printlist(Node* curr){
	while(curr!=nullptr){ //chcking if the current node empty or not
		cout<<curr->val;
		if(curr->next!=nullptr) //check if there is a next node
			cout<<" ";
		curr=curr->next;	
	}
	cout<<endl;
}

int main(){
	Node*head1=new Node(1);
	head1->next=new Node(2);
	head1->next->next=new Node(4);
	
	Node*head2=new Node(1);
	head2->next=new Node(3);
	head2->next->next=new Node(4);
	Node* res=sortedNodes(head1,head2);
	printlist(res);
}
