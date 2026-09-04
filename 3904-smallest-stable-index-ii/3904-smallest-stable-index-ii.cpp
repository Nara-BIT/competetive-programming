class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,1e9);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
            
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        bool possible=false;
        int ans=1e9;
        for(int i=0;i<n;i++){
            int stable=prefix[i]-suffix[i];
            if(stable<=k){
                possible=true;
                ans=min(ans,i);
            }
        }
        if(possible)
            return ans;
        return -1;
    }
};