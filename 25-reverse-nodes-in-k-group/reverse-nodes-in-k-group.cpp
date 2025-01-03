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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newhead=head,*test=head;
        int count=k;
        while(count-- && test){
            test=test->next;
        }
        if(count!=-1) return head;
        else{
            newhead = recc_rev(head,k,1);
            head->next=reverseKGroup(test,k);
            return newhead;
        }
    }
    ListNode* recc_rev(ListNode* head, int k,int val){
        if(k==val) return head;
        ListNode* newhead = recc_rev(head->next,k,val+1);
        head->next->next=head;
        head->next=nullptr;
        return newhead;
    }
};