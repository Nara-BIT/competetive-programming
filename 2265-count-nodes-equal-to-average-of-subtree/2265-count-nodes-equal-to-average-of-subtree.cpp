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
    int numNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=numNodes(root->left);
        int right=numNodes(root->right);
        return 1+left+right;
    }
    //long long sum=0;
    int sumNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=sumNodes(root->left);
        int right=sumNodes(root->right);
        return root->val+left+right;
    }
    int avg(TreeNode* root){
        int n=numNodes(root);
        int sum=sumNodes(root);
        return sum/n;
    }
    int cnt=0;
    void traverse(TreeNode* root){
        if(root==NULL){
            return;
        }
        traverse(root->left);
        traverse(root->right);
        if(root->val==avg(root)){
            cnt++;
        }
        return;
    }
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return cnt;
    }
};