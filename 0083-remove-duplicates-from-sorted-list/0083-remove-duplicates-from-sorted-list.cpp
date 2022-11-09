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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
        return head;
    }
    
    ListNode *temp, *p;  
    temp = head->next;
    p=head;
    while(temp!=NULL){
        
        if(temp->val == p->val){
            temp=temp->next;
    
        
        }else{
            p->next = temp;
            p =temp;
            temp = temp->next;
        }
    }
    if(temp==NULL)
        p->next = NULL;
    return head;
    }
};