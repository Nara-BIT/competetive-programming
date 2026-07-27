class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,pair<int,int>>mpp;
        int maxLength=-1;
        int n=nums.size();
        int sum=0;
        int curr_sum=0;
        for(int num:nums)
            sum+=num;
        for(int l=0,r=0;r<n;r++){
            curr_sum+=nums[r];
            while(l<=r && curr_sum>sum-x){
                curr_sum-=nums[l];
                l++;
            }
            if(curr_sum==sum-x)
            maxLength=max(maxLength,r-l+1);
                
        }
        return maxLength==-1?-1:n-maxLength;
        
    }
};