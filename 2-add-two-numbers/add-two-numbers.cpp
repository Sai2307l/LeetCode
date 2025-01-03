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
    void recc_add(ListNode* h1,ListNode* l1, ListNode* l2,int carry){
        if(l1==nullptr && l2==nullptr && carry==0){
            return;
        }
        if(l1==nullptr && l2==nullptr && carry!=0){
            h1->val=carry;
        }
        else if(l1!=nullptr && l2==nullptr){
            h1->val=(l1->val+carry)%10;
            ListNode* child = new ListNode();
            h1->next=child;
            recc_add(child,l1->next,l2,(int)(l1->val+carry)/10);
        }
        else if(l1==nullptr && l2!=nullptr){
            h1->val=(l2->val+carry)%10;
            ListNode* child = new ListNode();
            h1->next=child;
            recc_add(child,l1,l2->next,(int)(l2->val+carry)/10);
        }
        else{
            h1->val=(l1->val+l2->val+carry)%10;
            ListNode* child = new ListNode();
            h1->next=child;
            recc_add(child,l1->next,l2->next,(int)(l1->val+l2->val+carry)/10);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = new ListNode();
        ListNode* lastremove=h1;
        recc_add(h1,l1,l2,0);
        while(lastremove->next->next!=nullptr){
            lastremove=lastremove->next;
        }
        if(lastremove->next->val==0) lastremove->next=nullptr;
        return h1;
    }
};