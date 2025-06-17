#include <iostream>
#include <stack>
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

ListNode* reverseList(ListNode* head){
	ListNode* prev=nullptr, *current=head,*next;
	while(current){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		
	}
	return prev;
}

void printList(ListNode* current){
	while(current!=nullptr){
		cout<<current->data<<" ";
		current=current->next;
	}
}

ListNode* rearrange(ListNode* head){
	ListNode* slow=head,*fast=slow->next;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	ListNode *head1=head;
	ListNode *head2=slow->next;
	slow->next=NULL;
	
	head2=reverseList(head2);
	
	head=new ListNode(0);
	ListNode* current=head;
	while(head1||head2){
		if(head1){
			current->next=head1;
			current=current->next;
			head1=head1->next;
		}
		if(head2){
			current->next=head2;
			current=current->next;
			head2=head2->next;
		}
	}
	return head->next;
}

int main(){
	ListNode* head=new ListNode(10);
	head->next=new ListNode(11);
	head->next->next=new ListNode(12);
	head->next->next->next=new ListNode(13);
	head->next->next->next->next=new ListNode(14);
	head=rearrange(head);
	printList(head);
	return 0;
}
