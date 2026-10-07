class Solution {
public:
    int canAssign(vector<int>& nums,int mid,int k){
        int count=0;
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        vector<int>max_pos;
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int mid;
        int ans;
        while(low<=high){
            mid=low+(high-low)/2;
            if(canAssign(nums,mid,k)){
                high=mid-1;
                ans=mid;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};