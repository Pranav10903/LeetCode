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
    bool Identical(TreeNode *p,TreeNode *q)
    {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(p==NULL||q==NULL)
        {
            return false;
        }
        if(p->val!=q->val)
        {
            return false;
        }
        return Identical(p->right,q->left)&&Identical(p->left,q->right);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* p,*q;
        p = root->left;
        q = root->right;
        return Identical(p,q);
    }
};