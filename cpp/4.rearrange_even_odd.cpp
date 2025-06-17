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

void rearrangeEvenOdd(ListNode* head){
	if(head==nullptr||head->next==nullptr){
		return;
	}
	ListNode* oddHead=new ListNode(0);
	ListNode* evenHead=new ListNode(0);
	
	ListNode* odd=oddHead;
	ListNode* even=evenHead;
	
	ListNode* curr=head;
	int position=1;
	
	while(curr!=nullptr){
		if(position%2==1){
			odd->next=curr;
			odd=odd->next;
		}else{
			even->next=curr;
			even=even->next;
		}
		curr=curr->next;
		position++;
	}
	odd->next=evenHead->next;
	even->next=nullptr;
	head=oddHead->next;
	
	delete oddHead;
	delete evenHead;
}

int main(){
	ListNode* head=new ListNode(1) ;
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(5);
	
	rearrangeEvenOdd(head);
	ListNode* current=head;
	while(current!=nullptr){
		cout<<current->data<<" ";
		current=current->next;
	}
	cout<<endl;
	return 0;
}
