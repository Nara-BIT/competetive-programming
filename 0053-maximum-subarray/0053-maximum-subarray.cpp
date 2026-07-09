class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int curr_sum=0;
        for(int num:nums){
            curr_sum+=num;
            ans=max(curr_sum,ans);
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        return ans;
    }
};