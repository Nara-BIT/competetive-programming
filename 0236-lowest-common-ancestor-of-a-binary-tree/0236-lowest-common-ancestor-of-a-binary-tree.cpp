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
        TreeNode* lt=ancestor(root->left,p,q);
        TreeNode* rt=ancestor(root->right,p,q);

        if(lt==NULL)
            return rt;
        else if(rt==NULL)
            return lt;
        
        return root;
        //return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ancestor(root,p,q);
    }
};