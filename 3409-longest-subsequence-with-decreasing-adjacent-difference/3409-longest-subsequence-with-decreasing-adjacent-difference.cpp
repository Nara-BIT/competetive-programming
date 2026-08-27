class Solution {
public:
    
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(303,vector<int>(303,0));
        vector<vector<int>>suffix(301,vector<int>(301,0));
        int ans=0;
        for(int num:nums){
            int mx=0;
            for(int j=300;j>=0;j--){
                int ct=0;
                int prevL=num-j;
                int prevG=num+j;
                if(prevL>=0){
                    int l=1+dp[prevL][j];
                    ct=max(l,ct);
                }
                if(prevG<=300){
                    int l=1+dp[prevG][j];
                    ct=max(l,ct);
                }
                mx=max(mx,ct);
                dp[num][j]=mx;
                ans=max(mx,ans);
            }
        }
        return ans;
        
    }
};