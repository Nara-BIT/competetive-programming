class Solution {
public:
    int backtrack(int srt,int end,vector<int>&cuts,vector<vector<int>>&dp){
        if(srt>end){
            return 0;
        }
        if(dp[srt][end]!=-1)
            return dp[srt][end];
        int mini=INT_MAX;
        for(int i=srt;i<=end;i++){
            int steps=cuts[end+1]-cuts[srt-1]+backtrack(srt,i-1,cuts,dp)+backtrack(i+1,end,cuts,dp);
            mini=min(steps,mini);

        }

        return dp[srt][end]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return backtrack(1,m,cuts,dp);
    }
};