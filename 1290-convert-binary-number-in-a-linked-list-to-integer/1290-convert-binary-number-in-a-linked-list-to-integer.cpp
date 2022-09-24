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
    int getDecimalValue(ListNode* head) {
        ListNode *ptr = head;
        ListNode *temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp  = temp->next;
        }
        count--;
        int res = 0;
        while(count>=0){
            res+=((ptr->val)<<count);
            ptr = ptr->next;
            count--;
        }
        return res;
    }
};