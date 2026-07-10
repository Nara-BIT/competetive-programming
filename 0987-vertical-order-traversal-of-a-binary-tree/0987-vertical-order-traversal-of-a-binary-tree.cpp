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
    static bool compared(const vector<int>&a,const vector<int>&b){
        if(a[1]!=b[1]) { 
        return a[1]<b[1];
        }

        if(a[0]!=b[0]) {
            return a[0]<b[0];
        }
        
        return a[2]<b[2];
    }
    void ins(int row,int col,TreeNode* root,vector<vector<int>>&cords){
        if(root==NULL)
            return;
        cords.push_back({row,col,root->val});
        ins(row+1,col-1,root->left,cords);
        ins(row+1,col+1,root->right,cords);
        
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>cords;
        vector<vector<int>>res;
        if(root==NULL)
            return {};
        ins(0,0,root,cords);
        sort(cords.begin(),cords.end(),compared);
        int n=cords.size();
        map<int,vector<int>>mp;
        vector<int>temp;
        //temp.push_back(root->val);
        for(auto it:cords){
            mp[it[1]].push_back(it[2]);
        }
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};