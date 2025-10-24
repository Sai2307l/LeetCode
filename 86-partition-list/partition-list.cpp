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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;
        ListNode* small = new ListNode(-1) , *great = new ListNode(-1);
        ListNode* start = small,* end = great;
        ListNode* trav = head;
        while(trav){
            if(trav->val<x){
                small->next = trav;
                small = small->next;
            }else{
                great->next = trav;
                great = great->next;
            }
            trav = trav->next;
            small->next = nullptr;
            great->next = nullptr;
        }
        if(start->next && end->next){
            small->next = end->next;
            return start->next;
        }else if(start->next){
            return start->next;
        }else{
            return end->next;
        }
    }
};