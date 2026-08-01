class Solution {
public:
    int backtrack(int left, int right,vector<int>& nums,vector<vector<int>>&dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int lp=nums[left]+min(backtrack(left+2,right,nums,dp),backtrack(left+1,right-1,nums,dp));
        int rp=nums[right]+min(backtrack(left,right-2,nums,dp),backtrack(left+1,right-1,nums,dp));
        return dp[left][right]=max(lp,rp);
    }
    bool predictTheWinner(vector<int>& nums) {
        int t_sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int lk=backtrack(0,nums.size()-1,nums,dp);
        if(2*lk>=t_sum)
            return true;
        return false;
    }
};