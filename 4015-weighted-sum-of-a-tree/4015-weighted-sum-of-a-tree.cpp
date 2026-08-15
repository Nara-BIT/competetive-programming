class Solution {
public:
    long long calculate(vector<vector<int>>& adj,vector<int>&nums,int height){
        queue<pair<int,int>>q;
        q.push({0,1});
        long long sum=0;
        int index=0;
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int level=it.second;
            long long num=nums[node];
            sum+=(num*(height-level+1));
            q.pop();
            if(adj[node].empty())
                continue;
            for(int nbr:adj[node]){
                q.push({nbr,level+1});
            }
        }
        return sum;
        
    }
    int height(vector<vector<int>>& adj){
        queue<pair<int,int>>q;
        q.push({0,1});
        int ans=0;
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int level=it.second;
            ans=max(ans,level);
            int n=q.size();
            q.pop();
            if(adj[node].empty())
                continue;
            for(int it:adj[node]){
                q.push({it,level+1});
            }
        }
        return ans;

    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        int m=*max_element(parent.begin(),parent.end());
        vector<vector<int>>adj(n);
        

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        int ht=height(adj);
        long long ans=calculate(adj,nums,ht);
        return ans;

    }
};