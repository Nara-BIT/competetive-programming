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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        TreeNode* head=root;
        vector<vector<int>>res;
        if(root==NULL)
            return {};
        q.push(root);
        bool l2r=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=(l2r?i:n-i-1);
                if(node!=NULL){
                    temp[index]=node->val;
                }
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);

            }
            res.push_back(temp);
            l2r=!l2r;
        }
        return res;
    }
};