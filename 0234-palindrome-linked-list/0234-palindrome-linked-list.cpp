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
     bool checkPalindrome(ListNode* head , ListNode* &target , bool isEven){
        
        if(head == target){
            if(isEven == false)
                target = target -> next ;
            return true;
        }
        
        if(checkPalindrome(head -> next , target,isEven)==false)
            return false;
        
        if(head && !target)
            return false;
        
        if(head -> val == target -> val ){
            target = target -> next ;
            return true;
        }
        
        return false;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* singleJ = head ;
        ListNode* doubleJ = head ;
        
        while(doubleJ && doubleJ->next){
            
            singleJ = singleJ -> next ;
            doubleJ = doubleJ -> next -> next ;
            
        }
        
        ListNode* middle = singleJ;
        
        bool isEven ;
        
        if(doubleJ) isEven = false;
        else isEven = true;
        
        return checkPalindrome(head,middle,isEven);
        
        return true;
        
    }
};