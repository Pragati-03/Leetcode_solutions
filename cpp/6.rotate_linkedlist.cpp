#include <iostream>

using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int d) { 
        data = d; 
        next = nullptr;
    }
};

ListNode*rotate(ListNode*head,int k){
	if(k==0|| head==nullptr) 
	    return head;
	    
    for(int i=0;i<k;++i){
    	ListNode* current=head;
    	while(current->next!=nullptr)
    		current=current->next;
		current->next=head;
		current=current->next;
		head=head->next;
		current->next=nullptr;
	}	 
	return head;   		
}


void printList(ListNode* current){
	while(current!=nullptr){
		cout<<current->data<<" ";
		current=current->next;
	}
}

int main(){
	ListNode* head=new ListNode(10);
	head->next=new ListNode(11);
	head->next->next=new ListNode(12);
	head->next->next->next=new ListNode(13);
	head->next->next->next->next=new ListNode(14);
	cout<<"Before rotating: ";
	printList(head);
	cout<<endl;
	cout<<"After rotating: ";
	head=rotate(head,3);
	printList(head);
	return 0;
}
