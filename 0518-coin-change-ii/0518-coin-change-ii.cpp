class Solution {
public:
    /*int cnt(int ind,vector<int>&coins,int target,vector<vector<int>>& dp){
        if(ind==0){
            return (target%coins[0]==0);
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int nt=cnt(ind-1,coins,target,dp);
        int t=0;
        if(coins[ind]<=target)
            t=cnt(ind,coins,target-coins[ind],dp);
        return dp[ind][target]=t+nt;
    }*/
    int change(int amount, vector<int>& coins) {
        
        vector<unsigned long long> dp(amount + 1, 0); 
        dp[0] = 1;
        
        for (int c : coins) {
            for (int a = c; a <= amount; a++) {
                dp[a] += dp[a - c];
            }
        }
        
        return dp[amount];
    }
};