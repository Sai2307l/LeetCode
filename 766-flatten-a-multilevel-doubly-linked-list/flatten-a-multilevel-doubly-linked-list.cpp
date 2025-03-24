/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }

        Node* curr = head;
        while(curr != NULL){//flatten
            if(curr->child != NULL){
                Node * Next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
            //find tail
            while(curr->next != NULL){
                curr = curr->next;
            }// attach tail
            if(Next != NULL){
            curr->next = Next;
            Next->prev = curr;
            }
           
        }
        curr = curr->next;
        }
    return head;
    }
};