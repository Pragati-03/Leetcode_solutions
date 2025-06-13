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

// Function to check if the linked list is palindrome or not
bool isPalindrome(ListNode* head) {
    ListNode* currentNode = head;

    // Declare a stack
    stack<int> s;

    // Push all elements of the list to the stack
    while (currentNode != nullptr) {
        s.push(currentNode->data);
        currentNode = currentNode->next;
    }

    // Iterate in the list again and check by
  	// popping from the stack
    while (head != nullptr) {
      
        // Get the topmost element
        int c = s.top();
        s.pop();

        // Check if data is not same as popped element
        if (head->data != c) {
            return false;
        }

        // Move ahead
        head = head->next;
    }

    return true;
}

int main() {
  
    // Linked list : 1->2->3->2->1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    bool result = isPalindrome(head);

    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
