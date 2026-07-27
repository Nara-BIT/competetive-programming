class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>freq;
        int sum=0;
        freq[0]=1;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int diff=sum%k;
            if(diff<0)
                diff+=k;
        
            count+=freq[diff];
            
            freq[diff]++;
        }
        return count;
    }
};