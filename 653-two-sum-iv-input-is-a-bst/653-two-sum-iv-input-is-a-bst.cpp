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
    private:
    vector<int> v;
    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    public:
    bool findTarget(TreeNode* root, int k) {
        //find inorder traversal of the tree
        inorder(root);
        int l=0, r=v.size()-1,s;

        //using 2 pointer approach to find if a pair exists such that its total==k
        while(l<r) {
            s = v[l]+v[r];
            if(s == k)
                return true;
            if(s < k)
                l++;
            else
                r--;
        }

        return false;
    }
};