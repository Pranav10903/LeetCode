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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        priority_queue<pair<int,ListNode*>>pq;
        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            while(lists[i]!=NULL)
            {
                pq.push({-lists[i]->val,lists[i]});
                lists[i] = lists[i]->next;
            }
        }
        ListNode *head = NULL;
        ListNode *k = NULL;
        if(pq.empty()) return head;
        head = pq.top().second;
        k = head;
        pq.pop();
        while(!pq.empty())
        {
            k->next = pq.top().second;
            k = pq.top().second;
            pq.pop();
        }
        k->next = NULL;
        return head==NULL ? NULL : head;
    }
};