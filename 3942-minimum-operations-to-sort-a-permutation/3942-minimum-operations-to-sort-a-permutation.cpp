class Solution {
public:
    bool ascend(vector<int>&nums){
        int n=nums.size();
        if(n<=2)
            return true;
        int breaks=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                breaks++;
            }
        }
        return breaks<=1;
    }
    bool descend(vector<int>& nums){
        int n=nums.size();
        if(n<=2)
            return true;
        int breaks=0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[(i+1)%n]){
                breaks++;
            }
        }
        return breaks<=1;
    }
    int minOperations(vector<int>& nums) {
        bool rev=true;
        bool srt=true;
        int n=nums.size();
        int zero_idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                
                zero_idx=i;
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            int actual_val = nums[(zero_idx + i) % n];
            
            if (actual_val != i) {
                srt = false;
            }
            if (actual_val != (n - i) % n) {
                rev = false;
            }
        }
        
        int ans=INT_MAX;
        if(srt){
            ans=min(ans,zero_idx);
            ans=min(ans,(n-zero_idx)%n+2);
        }
        if(rev){
            int ops=(zero_idx+1)%n+1;
            ans=min(ans,ops);
            ans=min(ans,n-zero_idx);
        }
        return ans==INT_MAX?-1:ans;
    }
};