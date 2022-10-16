/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int c=0;
    unordered_map<long int,int>m;
    void solve(TreeNode* root,long int targetSum, long int sum)
    {
        if(!root) return;
        sum+=root->val;
        if(sum==targetSum) c++;  //if the running sum is equals to target just inc by 1...
        //checcking if there is a sum between the running sum that is equals to target
        if(m.find(sum-targetSum)!=m.end()) c+=m[sum-targetSum];
        m[sum]++;  //increment the current running Sum
        solve(root->left, targetSum, sum);
        solve(root->right, targetSum, sum);
        m[sum]--;
    }   
    int pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum,0);
        return c;
    }
};