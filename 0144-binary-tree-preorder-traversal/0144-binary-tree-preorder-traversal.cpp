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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preOrder;
        if(root==NULL){
            return preOrder;
        }
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            preOrder.push_back(node->val);
            s.pop();
            if(node->right!=NULL){
                s.push(node->right);
            }
            if(node->left!=NULL){
                s.push(node->left);
            }
        } return preOrder;
    }
};