class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=nums[n-1];
        int b=nums[n-2];
        int c=nums[n-3];
        int e,f,g;
        if(nums[0]<0 && nums[1]<0 && nums[n-1]>0){
            e=nums[0];
            f=nums[1];
            g=nums[n-1];
        }
        int ans=max(a*b*c,e*f*g);
        return ans;
    }
};