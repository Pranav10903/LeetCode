/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
void solve(Node *root,vector<int>&preorder){
    if(root==NULL){
        return;
    }
    preorder.push_back(root->val);
    for(int i=0;i < root->children.size() ; i++ ){
        solve(root->children[i],preorder);
    }
    return;
}
public:
    vector<int> preorder(Node* root) {
        vector<int>preorder;
        solve(root,preorder);
        return preorder;
    }
};