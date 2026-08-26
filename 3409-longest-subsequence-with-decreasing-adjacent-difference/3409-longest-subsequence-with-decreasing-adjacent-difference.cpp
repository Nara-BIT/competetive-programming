class Solution {
public:
    
    
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(301,vector<int>(301,0));
        vector<vector<int>>suffix(301,vector<int>(301,0));
        int ans=0;
        for(int num:nums){
            if(dp[num][0]<1){
                dp[num][0]=1;
            }
            for(int prev=1;prev<=300;prev++){
                int dnew=abs(num-prev);
                int len=suffix[prev][dnew];
                if(len>0){
                    dp[num][dnew]=max(dp[num][dnew],1+len);

                }
                else{
                    if(suffix[prev][0]>0)
                        dp[num][dnew]=max(dp[num][dnew],2);
                }
                ans=max(ans,dp[num][dnew]);
            }
            suffix[num][299]=dp[num][299];
            for(int i=299;i>=0;i--){
                suffix[num][i]=max(dp[num][i],suffix[num][i+1]);
            }
        }
        return ans;
        
    }
};