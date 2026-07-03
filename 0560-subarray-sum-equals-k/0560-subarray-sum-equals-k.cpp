class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        int count=0;
        int sum=0;
        int diff;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            diff=sum-k;
            count+=mpp[diff];
            mpp[sum]++;
        }
        return count;
    }
};