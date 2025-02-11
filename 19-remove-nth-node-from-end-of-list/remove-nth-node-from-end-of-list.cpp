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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* high=head,*low=head;
        for(int i=0;i<n;i++)high=high->next;
        if(high==nullptr) return head->next;
        while(high->next!=nullptr){
            high=high->next;
            low=low->next;
        }
        low->next=low->next->next;
        return head;
    }
};