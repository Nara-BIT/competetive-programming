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
    /*static bool compared(const vector<int>&a,const vector<int>&b){
        if(a[1]!=b[1]) { 
        return a[1]<b[1];
        }
        if(a[0]!=b[0]) {
            return a[0]>b[0];
        }
        return a[2]<b[2];
    }*/
    void backtrack(TreeNode* root,int level,vector<int>&res){
        if(root==NULL)
            return;
        if(level==res.size())
            res.push_back(root->val);
        backtrack(root->right,level+1,res);
        backtrack(root->left,level+1,res);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        backtrack(root,0,res);
        return res;
    }
};