/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* getMin(vector<ListNode*>&arr){
        ListNode* min_=nullptr;
        int index=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==nullptr) continue;

            if(min_==nullptr || arr[i]->val< min_->val){
                index=i;
                min_=arr[i];
            }
        }
        if(index!=-1) arr[index] = arr[index]->next;

        return min_;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        ListNode* min_=getMin(lists);
        while (min_!=nullptr){
            tail->next=min_;
            tail=min_;
            min_=getMin(lists);
        }
        return dummy->next;
    }
};
