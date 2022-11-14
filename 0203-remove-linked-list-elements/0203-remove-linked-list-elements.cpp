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
    ListNode* removeElements(ListNode* head, int target) {
         ListNode *temp = head;
        
        if(head==NULL) return head;
        while(head!=nullptr && head->val==target){
            head = head->next;
        }
        
        while(temp!=NULL && temp->next!=NULL){
            
            if(temp->next->val == target){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
            
        }
        return head;
    }
};