class Solution {
public:
    int ans=-1,cnt=1,st=1;
    void dfs(int node,vector<int>&visit,vector<int>&edges){
        if(edges[node]==-1)
            return;
        if(visit[node]!=0){
            if(visit[node]>=st){
                ans=max(ans,cnt-visit[node]);
            }
            return;
        }
        visit[node]=cnt;
        cnt++;
        dfs(edges[node],visit,edges);

    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>visit(n,0);
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                dfs(i,visit,edges);
                st=cnt;
            }
        }
        return ans;
    }
};