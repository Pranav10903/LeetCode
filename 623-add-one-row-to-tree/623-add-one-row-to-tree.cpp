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
    void helper(TreeNode* root, int cd, int val, int depth) {
      if(!root)
            return;
        
        helper(root->left, cd+1, val, depth);
        helper(root->right, cd+1, val, depth);
        
        // Do the operation upon return from leaf as that traversed part is not touched again. 
        if(cd == depth-1){
            TreeNode *newNodeL = new TreeNode(val);
            TreeNode *tmp = root->left;
            root->left = newNodeL;
            newNodeL->left = tmp;
            
            TreeNode *newNodeR = new TreeNode(val);
            tmp = root->right;
            root->right = newNodeR;
            newNodeR->right = tmp;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        helper(root, 1, val, depth);
        return root;   
    }
};