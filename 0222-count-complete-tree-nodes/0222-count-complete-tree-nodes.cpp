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
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int lh = FindHeightLeft(root);
        int rh = FindRightHeight(root);
        if(lh==rh)
        {
            return (1<<lh)-1;
        }
        return 1+countNodes(root->right)+countNodes(root->left);
    }
    int FindHeightLeft(TreeNode *root)
    {
       int height = 0;
        while(root!=NULL)
        {
            height++;
            root = root->left;
        } return height;
    }
    int FindRightHeight(TreeNode *node)
    {
        int ht;
        while(node!=NULL)
        {
            ht++;
            node = node->right;
        } return ht;
    }
};