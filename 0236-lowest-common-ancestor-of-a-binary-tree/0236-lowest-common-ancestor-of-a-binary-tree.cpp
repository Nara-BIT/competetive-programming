/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ancestor(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left=ancestor(root->left,p,q);
        TreeNode* right=ancestor(root->right,p,q);
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        return root;
        //return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ancestor(root,p,q);
    }
};