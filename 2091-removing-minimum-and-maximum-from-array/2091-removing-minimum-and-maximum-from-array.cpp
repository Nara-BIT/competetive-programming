class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        int maxi=INT_MIN,mini=INT_MAX;
        for(int k=0;k<n;k++){
            if(maxi<nums[k]){
                maxi=nums[k];
                i=k;
            }
            if(mini>nums[k]){
                mini=nums[k];
                j=k;
            }
        }
        if(n==1){
            return 1;
        }
        int ans=0,lt,rt,lrt;
        lt=max(j+1,i+1);
        rt=max(n-i,n-j);
        lrt=min(i+1+n-j,j+1+n-i);
        ans=min(lt,min(rt,lrt));

        return ans;

    }
};