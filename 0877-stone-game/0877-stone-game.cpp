class Solution {
public:
    int backtrack(int i,int j,vector<int>& piles,vector<vector<int>>& dp){
        if(i==j){
            return piles[i];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int left=piles[i]-backtrack(i+1,j,piles,dp);
        int right=piles[j]-backtrack(i,j-1,piles,dp);
        return dp[i][j]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        if(backtrack(0,piles.size()-1,piles,dp)>0)
            return true;
        return false;
    }
};