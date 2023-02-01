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
    void solve( TreeNode *root , vector<string> &ans, string cur){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(cur+="->"+to_string(root->val));
            cout<<cur<<endl;
        }
        if(root->left){
            solve(root->left,ans,cur+"->"+to_string(root->val));
        }
        if(root->right){
            solve(root->right,ans,cur+"->"+to_string(root->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> ans;
         if(root == NULL){
             return ans;
         }
         if(!root->left && !root->right){
             ans.push_back(to_string(root->val));
         }
         if(root->left)solve(root->left, ans,to_string(root->val));
         if(root->right)solve(root->right, ans,to_string(root->val));
         return ans;
    }
};