class Solution {
public:
    
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(301,vector<int>(301,0));
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int nxt=1;nxt<=300;nxt++){
                int diff=abs(nums[i]-nxt);
                dp[nums[i]][diff]=max(dp[nums[i]][diff],1+dp[nxt][diff]);
                
            }
            for(int diff=1;diff<=299;diff++){
                dp[nums[i]][diff]=max(dp[nums[i]][diff],dp[nums[i]][diff-1]);
                ans=max(ans,dp[nums[i]][diff]);
            }
        }
        
        return ans;
        
    }
};