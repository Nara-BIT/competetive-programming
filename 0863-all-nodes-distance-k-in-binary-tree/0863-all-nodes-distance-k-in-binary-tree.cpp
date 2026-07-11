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
    void markParent(TreeNode* root,map<TreeNode*,TreeNode*>&parent){
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
       }
       return;
       
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }
        
        map<TreeNode*,TreeNode*>parent;
        map<TreeNode*,bool>visit;
        TreeNode* head=root;
        markParent(head,parent);
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        visit[target]=true;
        int level=0;
        vector<int>res;
        while(!q.empty()){
            int n=q.size();
            if(level++==k){
                break;
            }
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                int dist=q.front().second;
                q.pop();
                if(node->left && !visit[node->left]){
                    q.push({node->left,dist+1});
                    visit[node->left]=true;
                    if(dist+1==k){
                        res.push_back(node->left->val);
                    }
                }
                if(node->right && !visit[node->right]){
                    q.push({node->right,dist+1});
                    visit[node->right]=true;
                    if(dist+1==k){
                        res.push_back(node->right->val);
                    }
                }
                if(parent[node] && !visit[parent[node]]){
                    q.push({parent[node],dist+1});
                    visit[parent[node]]=true;
                    if(dist+1==k){
                        res.push_back(parent[node]->val);
                    }
                }
            }

        }
        return res;
    }
};