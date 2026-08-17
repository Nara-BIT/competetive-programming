class Solution {
public:
    int ans=0;
    /*void houseRobber(int ind,vector<int>&nums,int solu){
        if(ind>=nums.size()){
            return;
        }
        ans=max(ans,solu);
        for(int i=ind+2;i<nums.size();i++){
            solu+=nums[i];
            houseRobber(i,nums,solu);
            solu-=nums[i];
        }
        return;
    }*/
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int i,j;
        int temploot=0;
        if(n<2)
            return nums[0];
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        /*houseRobber(0,nums,nums[0]);
        houseRobber(1,nums,max(nums[0],nums[1]));
        return ans;*/
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};