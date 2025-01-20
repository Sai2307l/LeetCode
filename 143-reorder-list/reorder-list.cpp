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
ListNode* recc_sol(ListNode* head){
        if(head==nullptr)  return nullptr;
        if(head->next==nullptr) return head;
        if(head->next->next==nullptr) return head;
        ListNode* newhead=head->next,*last,*prev=head;
        while(prev->next->next!=nullptr){
            prev=prev->next;
        }
        last=prev->next;
        prev->next=nullptr;
        head->next=last;
        last->next=recc_sol(newhead);
        cout<<head->val<<endl;
        return head;
        }
    void reorderList(ListNode* head) {
        recc_sol(head);
    }
};