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
    bool isBalanced(TreeNode* root) {
        return DFS(root)!=-1;
    }
    int DFS(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int Lheight = DFS(root->left);
        int Rheight = DFS(root->right);
        if(Lheight==-1||Rheight==-1)
        {
            return -1;
        }
        if(abs(Lheight-Rheight)>1)
        {
            return -1;
        }
        return 1+max(Lheight,Rheight);
    }
            
            
};