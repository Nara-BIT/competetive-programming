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
    //vector<vector<int>>take(10000,0),dont_take(1000,0);
    map<TreeNode*,int>take,dont_take;
    void dfs(TreeNode* node){
        take[node]=node->val;
        dont_take[node]=0;
        if(node->left){
            dfs(node->left);
            take[node]+=dont_take[node->left];
            dont_take[node]+=max(dont_take[node->left],take[node->left]);
        }
        if(node->right){
            dfs(node->right);
            take[node]+=dont_take[node->right];
            dont_take[node]+=max(dont_take[node->right],take[node->right]);
        }
        return;
    }
    int rob(TreeNode* root) {
       dfs(root);
       return max(take[root],dont_take[root]); 
    }
};